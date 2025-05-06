#include <stdio.h>
#include <stdlib.h>

typedef struct node  node;
typedef struct node* nptr;

struct node {
    int n;
    nptr nxt, pre;
};

nptr head, tail;
int size;

// 申请空间
nptr newnode() {
    return (nptr)malloc(sizeof(node));
}

// 创建结点
nptr getnode(int n) {
    nptr p = newnode();
    p -> n = n;
    p -> nxt = p -> pre = NULL;
    return p;
}

// 将 p 插在链表的头部
void insert_head(nptr p) {
    size++;
    if(size == 1) {
        head = tail = p;
        return ;
    }
    p -> nxt = head;
    head -> pre = p;
    head = p;
}

// 将 p 插在链表尾部
void insert_tail(nptr p) {
    size++;
    if(size == 1) {
        head = tail = p;
        return ;
    }
    tail -> nxt = p;
    p -> pre = tail;
    tail = p;
}

// 将 p 插在链表上的元素 elm 之后
void insert_after(nptr elm, nptr p) {
    if(elm == tail) 
        insert_tail(p);
    else {
        // 这段代码中有一个很关键的点就是 elm -> nxt = p 一定要写在 elm -> nxt -> pre = p 和 p -> nxt = elm -> nxt 之后
        size++;
        p -> nxt = elm -> nxt;
        elm -> nxt -> pre = p;
        elm -> nxt = p;
        p -> pre = elm;
    }
}

// 将 p 插在链表上的元素 elm 之前
void insert_before(nptr elm, nptr p) {
    if(elm == head) 
        insert_head(p);
    else {
        // 这段代码中有一个很关键的点就是 elm -> pre = p 一定要写在 elm -> pre -> nxt = p 和 p -> pre = elm -> pre 之后
        size++;
        elm -> pre -> nxt = p;
        p -> pre = elm -> pre;
        p -> nxt = elm;
        elm -> pre = p;
    }
}

// 寻找 n 在链表中对应的第一个结点
nptr query(int n) {
    for(nptr i = head; i; i = i -> nxt)
        if(i -> n == n)
            return i;
    return NULL;// not found
}

// 删除链表中的元素 p ,应该确保元素 p 在链表中
void del(nptr p) {
    size--;

    if(size == 0) { // 特殊情况 size = 0
        head = tail = NULL;
        free(p);
        return ;
    }

    if(p == head) { // 特殊情况 p 是头结点
        head = head -> nxt;
        head -> pre = NULL;
    }
    else if(p == tail) { // 特殊情况 p 是尾结点
        tail = tail -> pre;
        tail -> nxt = NULL;
    }
    else { // p 在中间的情况
        p -> pre -> nxt = p -> nxt;
        p -> nxt -> pre = p -> pre;
    }

    free(p);
}

// 初始化链表函数
void init() {
    head = tail = NULL;
    size = 0;
}

int main() {
    init();
    int n;
    scanf("%d", &n);

    // 插入 n 个结点
    for(int i = 1; i <= n; i++)
        insert_tail(getnode(i));

    // 删除 n 个结点，这里只是为了展示 query 的用法
    for(int i = 1; i <= n; i++) {
        nptr p = query(i);
        if(p) del(p); // 如果在链表中有对应的结点再删
    }

    return 0;
}