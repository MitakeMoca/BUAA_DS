/*
    n 人从 1 到 n 编号围成一圈，从第 j 个人开始，依次报数，每次报到 k 的人出圈，问：出圈顺序 / 最后一个剩下的人
    输入：n j k
    输出：n 个人的出圈顺序
    
    示例输入：20 1 2
    示例输出：2 4 6 8 10 12 14 16 18 20 3 7 11 15 19 5 13 1 17 9
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int read() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

typedef struct node  node;
typedef struct node* nptr;

struct node {
    int id;
    nptr prev;
    nptr next;
};

nptr head, tail;
int size;

nptr newnode() {return (nptr)malloc(sizeof(node));}
nptr getnode(int id) {
    nptr p = newnode();
    p -> id = id;
    p -> next = p -> prev = NULL;
    return p;
}

int main() {
    int n = read(), j = read(), k = read();
    // 创建链表
    for(int i = 1;i <= n;i++) {
        nptr p = getnode(i);

        if(head == NULL)
            head = tail = p;
        else
            tail -> next = p, p -> prev = tail, tail = p;
    }

    // 闭环
    tail -> next = head;
    head -> prev = tail;
    size = n;

    // 找到第一个开始报数的人
    for(int i = 1; i < j ;i++) {
        head = head -> next;
    }

    // 模拟出链的操作
    nptr now = head;
    while(size) {
        // 报数
        for(int i = 1; i < k ;i++)
            now = now -> next;

        // now 应该出圈的人，让 now 出圈
        nptr p = now;
        p -> prev -> next = p -> next;
        p -> next -> prev = p -> prev;
        size--;
        printf("%d ", p -> id);

        // 让 now 重新变成下一次报数开始报 1 的人
        now = now -> next;
    }

    return 0;
}