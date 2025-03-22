#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node  node;
typedef struct node* nptr;

int read() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

char str[1005];
int vis[205];

struct node {
    char c;
    nptr prev;
    nptr next;
};

nptr head, tail;

nptr newnode() {return (nptr)malloc(sizeof(node));}
nptr getnode(char c) {
    nptr p = newnode();
    p -> c = c;
    p -> next = NULL;
    return p;
}

int size = 0;   // 链表大小
char ans[205];
void insert(char c) {
    if(!head)
        head = tail = getnode(c), size = 1;
    else {
        size++;
        nptr p = getnode(c);
        tail -> next = p;
        p -> prev = tail;
        tail = p;
    }
}

nptr encrypt(nptr now, int step) {
    char c = now -> c;
    nptr p = now -> next;
    now -> prev -> next = now -> next;
    now -> next -> prev = now -> prev;
    step--;
    while(step--)
        p = p -> next;
    size--;
    ans[c] = p -> c;
    printf("%c", ans[c]);
    return p;
}

int main() {
    gets(str);
    int len = strlen(str);

    for(int i = 0;i < len;i++)
        if(!vis[str[i]])
            insert(str[i]), vis[str[i]] = 1;

    for(int i = 32;i <= 126;i++)
        if(!vis[i])
            insert(i);

    tail -> next = head;
    head -> prev = tail;

    nptr p = head;

    char tem = head -> c;
    while(size != 1)    {
        int step = head -> c;
        head = encrypt(head, step);
    }

    ans[head -> c] = tem;

    puts(ans + 32);
    printf("%c\n", ans['e']);

    // 文件 io
    freopen("in.txt", "rb", stdin);
    freopen("in_crpyt.txt", "wb", stdout);
    char ch;
    while(~scanf("%c", &ch)) {
        if(ch >= 32 && ch <= 126)
            printf("%c", ans[ch]);
        else printf("%c", ch);
    }

    return 0;
}