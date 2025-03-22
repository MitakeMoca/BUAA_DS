#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node  node;
typedef struct node* nptr;

// 按照指数对其中的节点排序
struct node {
    int x, z;
    nptr next;
};

nptr headA, tailA;  // 表示两个多项式的头部
nptr headB, tailB;
nptr head, tail;   // 代表答案多项式

int read() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

nptr newnode()  {return (nptr)malloc(sizeof(node));}
nptr getnode(int x, int z) {
    nptr p = newnode();
    p -> x = x;
    p -> z = z;
    p -> next = NULL;
    return p;
}

void insert(int x, int z) {
    if(!head)
        head = tail = getnode(x, z);
    else if(z > head -> z) {
        nptr p = getnode(x, z);
        p -> next = head;
        head = p;
    } else if(z < tail -> z) {
        nptr p = getnode(x, z);
        tail -> next = p;
        tail = p;
    } else {
        for(nptr p = head; p ; p = p -> next) 
            if(p -> z == z) {
                p -> x += x;
                return ;
            }

        // 否则，就插在中间两个元素之间
        nptr p = head, q = head -> next;
        while(1) {
            if(p -> z > z && q -> z < z) {  // 插在 p q 之间
                nptr r = getnode(x, z);
                p -> next = r;
                r -> next = q;
                return ;
            }
            p = p -> next;
            q = q -> next;
        }
    }
}

int main() {
    int x, z;
    char ch;

    while(scanf("%d%d%c", &x, &z, &ch)) {
        if(!headA)  
            tailA = headA = getnode(x, z);
        else {
            nptr p = getnode(x, z);
            tailA -> next = p;
            tailA = tailA -> next;
        }
        if(ch != ' ')
            break;
    }


    while(scanf("%d%d%c", &x, &z, &ch)) {
        if(!headB)  tailB = headB = getnode(x, z);
        else {
            nptr p = getnode(x, z);
            tailB -> next = p;
            tailB = tailB -> next;
        }
        if(ch != ' ')
            break;
    }

    for(nptr p = headA; p ; p = p -> next)
        for(nptr q = headB; q ; q = q -> next)
            insert(p -> x * q -> x, p -> z + q -> z);

    for(nptr p = head; p ; p = p -> next) 
        if(p -> x)
            printf("%d %d ", p -> x, p -> z);
    
    return 0;
}