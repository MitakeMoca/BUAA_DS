#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct node  node;
typedef struct node* nptr;

struct node {
    int cnt;
    char *str;
    nptr ls, rs;
};

nptr newnode() {
    return (nptr)malloc(sizeof(node));
}

nptr getnode(char *s) {
    nptr p = newnode();
    p -> str = (char *)malloc(strlen(s) + 1);
    strcpy(p -> str, s);
    p -> cnt = 1;
    p -> ls = NULL;
    p -> rs = NULL;
    return p;
}

char word[105];
nptr root;

void dfs(nptr p, char *s) {
    if(p == NULL)
        return ;
    if(strcmp(s, p -> str) == 0) {
        p -> cnt++;
        return ;
    }
    if(strcmp(s, p -> str) < 0) {
        if(p -> ls == NULL)
            p -> ls = getnode(s);
        else
            dfs(p -> ls, s);
    } else {
        if(p -> rs == NULL)
            p -> rs = getnode(s);
        else
            dfs(p -> rs, s);
    }
}

void insert(char *s) {
    if(root == NULL) {
        root = getnode(s);
        return ;
    } 
    dfs(root, s);
}

void preDfs(nptr p) {
    if(p == NULL)
        return ;
    preDfs(p -> ls);
    printf("%s %d\n", p -> str, p -> cnt);
    preDfs(p -> rs);
}

int main() {
    freopen("article.txt", "r", stdin);
    char ch;
    int len = 0;
    while((ch = getchar()) != EOF) {
        if(!isalpha(ch)) {
            if(len > 0) {
                word[len] = 0;
                insert(word), len = 0;
            }
        } else 
            word[len++] = tolower(ch);
    }
    if(len > 0) 
        word[len] = 0, insert(word);

    nptr p = root;
    len = 0;    // len 再就业
    while(p && len < 3)
        printf("%s ", p -> str), p = p -> rs, len++;
    printf("\n");

    preDfs(root);
    return 0;
}