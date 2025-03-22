#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node  node;
typedef struct node* nptr;

struct node {
    int x1, y1;
    int x2, y2;
    nptr next;
};

nptr newnode() {return (nptr)malloc(sizeof(node));}
nptr getnode(int x1, int y1, int x2, int y2) {
    nptr p = newnode();
    p -> x1 = x1;
    p -> y1 = y1;
    p -> x2 = x2;
    p -> y2 = y2;
    p -> next = NULL;
    return p;
}

nptr findTail(nptr p) {
    while(p -> next)
        p = p -> next;
    return p;
}

int findLinkNum(nptr p) {
    int ret = 0;
    while(p)
        ret++, p = p -> next;
    return ret;
}

int read() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

nptr a[10005];

int main() {
    int n = read();
    for(int i = 1;i <= n;i++) {
        int x1 = read(), y1 = read(), x2 = read(), y2 = read();
        a[i] = getnode(x1, y1, x2, y2);
    }

    // 看看该结点能接在谁后面
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) {
            if(a[i] -> x2 == a[j] -> x1 && a[i] -> y2 == a[j] -> y1)
                a[i] -> next = a[j];
            nptr tail = findTail(a[j]);
            if(a[i] -> x1 == tail -> x2 && a[i] -> y1 == tail -> y2)
                tail -> next = a[i];
        }

    int ans = 0, x = 0, y = 0;
    for(int i = 1; i <= n; i++)
        if(findLinkNum(a[i]) > ans)
            ans = findLinkNum(a[i]), x = a[i] -> x1, y = a[i] -> y1;
    printf("%d %d %d", ans, x, y);
    return 0;
}