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
    int id, num;
    nptr son[3];
};

nptr newnode() {
    return (nptr)malloc(sizeof(node));
}

nptr getnode(int id) {
    nptr p = newnode();
    p -> id = id;
    for(int i = 0; i < 3; i++)
        p -> son[i] = NULL;
    return p;
}

nptr p;
void find(nptr q, int n) {
    if(q == NULL)
        return ;
    if(q -> id == n) {
        p = q;
        return ;
    }
    for(int i = 0; i < 3; i++) {
        find(q -> son[i], n);
    }
}

node a[1005];

int cmp(const void *a, const void *b) {
    node *x = (node *)a;
    node *y = (node *)b;
    if(x -> num == y -> num)
        return x -> id - y -> id;
    return y -> num - x -> num;
}

nptr que[1005];
int front = 0, rear = -1;

void enqueue(nptr a) {
    que[++rear] = a;
}

nptr dequeue() {
    return que[front++];
}

int isEmpty() {
    return front > rear;
}

void bfs(nptr root) {
    enqueue(root);
    int cnt = 0;
    while(!isEmpty()) {
        nptr p = dequeue();
        // 登机口输出
        if(p -> id < 100)
            printf("%d->%d\n", a[cnt++].id, p -> id);
        for(int i = 0; i < 3; i++) {
            if(p -> son[i] != NULL)
                enqueue(p -> son[i]);
        }
    }
}

int main() {
    nptr root = NULL;
    root = getnode(100);
    int n;
    while((n = readInt()) != -1) {
        find(root, n);
        // find 之后，p 就是当前结点
        int m, cnt = 0;
        while((m = readInt()) != -1) {
            nptr q = getnode(m);
            p -> son[cnt++] = q;
        }
    }

    int id, num, i = 0;
    // 不定组输入用 ctrl + z
    while(scanf("%d %d", &id, &num) != EOF) {
        a[i].id = id, a[i].num = num;
        i++;
    }

    qsort(a, i, sizeof(node), cmp);
    bfs(root);
}