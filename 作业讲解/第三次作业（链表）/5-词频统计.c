#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node  node;
typedef struct node* nptr;

int readInt() {
    int tem;
    scanf("%d",&tem);
    return tem;
}
struct node {
    char str[25];
    int cnt;
    nptr next;
};
nptr head, tail;

nptr newnode() {return (nptr)malloc(sizeof(node));}
nptr getnode(char *str) {
    nptr p = newnode();
    strcpy(p -> str, str);
    p -> cnt = 1;
    p -> next = NULL;
    return p;
}

void insert(char * word) {
    if(!head)
        head = tail = getnode(word);
    else {
        if(strcmp(head -> str, word) > 0) {
            nptr p = getnode(word);
            p -> next = head;
            head = p;
        } else if(strcmp(tail -> str, word) < 0) {
            nptr p = getnode(word);
            tail -> next = p;
            tail = p;
        } else {
            for(nptr p = head; p ; p = p -> next) 
                if(strcmp(p -> str, word) == 0) {
                    p -> cnt++;
                    return ;
                }
            nptr p = head, q = head -> next;
            while(1) {
                if(strcmp(p -> str, word) < 0 && strcmp(q -> str, word) > 0) {
                    nptr t = getnode(word);
                    p -> next = t;
                    t -> next = q;
                    return ;
                }
                p = p -> next;
                q = q -> next;
            }
        }
    }
}

char nowWord[25];
char line[10005];

int main() {
    freopen("article.txt", "rb", stdin);
    int nowSize = 0;
    while(gets(line)) {
        int len = strlen(line);
        for(int i = 0;i < len;i++) 
            if(line[i] >= 'a' && line[i] <= 'z' || line[i] >= 'A' && line[i] <= 'Z' ) {
                while(line[i] >= 'a' && line[i] <= 'z' || line[i] >= 'A' && line[i] <= 'Z' )
                    nowWord[nowSize++] = tolower(line[i]), i++;
                nowWord[nowSize] = 0;
                insert(nowWord);
                nowSize = 0;
            }
    }

    for(nptr p = head; p ; p = p -> next)
        printf("%s %d\n", p -> str, p -> cnt);

    return 0;
}