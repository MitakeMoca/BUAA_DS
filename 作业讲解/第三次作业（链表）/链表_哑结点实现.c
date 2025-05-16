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

// 将 p 插在链表上的元素 elm 之后
// 哑结点保证了每个节点都一定有前驱和后继
void insert_after(nptr elm, nptr p) {
    size++;
    elm -> nxt -> pre = p;
    p -> nxt = elm -> nxt;
    p -> pre = elm;
    elm -> nxt = p; 
}

// 将 p 插在链表上的元素 elm 之前
void insert_before(nptr elm, nptr p) {
    size++;
    elm -> pre -> nxt = p;
    p -> pre = elm -> pre;
    p -> nxt = elm;
    elm -> pre = p;
}

// 将 p 插在链表的头部（即头结点之后）
void insert_head(nptr p) {
    insert_after(head, p);
}

// 将 p 插在链表尾部
void insert_tail(nptr p) {
    insert_before(tail, p);
}

// 寻找 n 在链表中对应的第一个结点
nptr query(int n) {
    // 注意，遍历的时候要跳过 head 和 tail
    for(nptr i = head -> nxt; i != tail; i = i -> nxt)
        if(i -> n == n)
            return i;
    return NULL;// not found
}

// 删除链表中的元素 p ,应该确保元素 p 在链表中
void del(nptr p) {
    size--;
    p -> pre -> nxt = p -> nxt;
    p -> nxt -> pre = p -> pre;

    free(p);
}

// 初始化链表函数
void init() {
    head = getnode(0);
    tail = getnode(0);
    head -> nxt = tail;
    tail -> pre = head;
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