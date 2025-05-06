#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 循环链表
typedef struct node  node;
typedef struct node* nptr;

struct node {
    int sz, pos;
    nptr prev;
    nptr next;
};

nptr newnode()  {return (nptr)malloc(sizeof(node));}
nptr getnode(int sz, int pos)  {
    nptr p = newnode();
    p -> sz = sz;
    p -> pos = pos;
    p -> next = NULL;
    p -> prev = NULL;
    return p;
}

int readInt() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

nptr head, tail;
nptr alloc(nptr now, int sz) {
    nptr p = now, ret = NULL;
    do {
        if(p -> sz >= sz) {
            ret = p;
            break;
        }
        p = p -> next;
    } while(p != now);
    
    if(ret != NULL) {
        if(ret -> sz == sz) {
            ret -> next -> prev = ret -> prev;
            ret -> prev -> next = ret -> next;
            if(ret -> next == ret)
                return NULL;
            return ret -> next;
        } else {
            ret -> sz -= sz;
            return ret;
        }
    }
    return now;
}

int main() {
    int n = readInt();
    for(int i = 1; i <= n; i++) {
        int pos = readInt(), sz = readInt();
        if(head == NULL)    head = tail = getnode(sz, pos);
        else {
            nptr p = getnode(sz, pos);
            tail -> next = p;
            p -> prev = tail;
            tail = p;
        }
    }

    head -> prev = tail;
    tail -> next = head;

    nptr now = head;
    int sz;
    while((sz = readInt()) != -1) 
        now = alloc(now, sz);

    nptr tem = now;
    if(now != NULL)
        printf("%d %d\n", now -> pos, now -> sz), now = now -> next;
    for(nptr p = now; p != tem;p = p -> next)
        printf("%d %d\n", p -> pos, p -> sz);
    return 0;
}