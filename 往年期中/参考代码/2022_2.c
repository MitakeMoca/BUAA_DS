#include <stdio.h>
#include <stdlib.h>

int readInt() {
    int tem;
    scanf("%d", &tem);
    return tem;
}

typedef struct node  node;
typedef struct node* nptr;
struct node {
    int val, cnt;
    nptr pre, nxt;
};
nptr head, tail;

nptr newnode() {
    return (nptr)malloc(sizeof(node));
}

nptr getnode(int val) {
    nptr p = newnode(); 
    p -> val = val;
    p -> cnt = 1;
    p -> pre = p -> nxt = NULL;
    return p;
}

void init() {
    head = getnode(0);
    tail = getnode(0);
    head -> nxt = tail;
    tail -> pre = head;
}

int cmp_cnt = 0;
nptr find(int val) {
    nptr p = head -> nxt;
    while(p != tail) {
        cmp_cnt++;
        if(p -> val == val)
            return p;
        p = p -> nxt;
    }
    return NULL;
}

void insert_back(nptr p) {
    tail -> pre -> nxt = p;
    p -> pre = tail -> pre;
    p -> nxt = tail;
    tail -> pre = p;
}

void insert_front(nptr p) {
    // 从链表中删除 p
    p -> pre -> nxt = p -> nxt;
    p -> nxt -> pre = p -> pre;

    // 重新插入 p
    head -> nxt -> pre = p;
    p -> nxt = head -> nxt;
    p -> pre = head;
    head -> nxt = p;
    p -> cnt += 1;
}

int main() {
    int n = readInt();
    // 初始化链表
    init();

    for(int i = 1; i <= n; i++) {
        int r = readInt();
        nptr p = find(r);
        if(p == NULL) 
            insert_back(getnode(r));
        else
            insert_front(p);
    }

    printf("%d\n", cmp_cnt);
    int cnt = 0;
    nptr p = head -> nxt;
    while(p != tail && cnt < 5) {
        printf("%d %d\n", p -> val, p -> cnt);
        cnt++;
        p = p -> nxt;
    }
    
    return 0;
}