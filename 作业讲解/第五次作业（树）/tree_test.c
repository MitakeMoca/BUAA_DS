#include <stdio.h>
#include <stdlib.h>

typedef struct node  node;
typedef struct node* nptr;

struct node {
    char i;
    nptr ls, rs;
};
nptr root;

nptr newNode() {
    return (nptr)malloc(sizeof(node));
}

nptr getNode(char ch) {
    nptr p = newNode();
    p -> i = ch;
    p -> ls = NULL;
    p -> rs = NULL;
    return p;
}

void inDfs(nptr p) {
    if(p == NULL)
        return ;
   	inDfs(p -> ls);
    printf("%c ", p -> i);
    inDfs(p -> rs);
}

void preDfs(nptr p) {
    if(p == NULL)
        return ;
    printf("%c ", p -> i);
   	preDfs(p -> ls);
    preDfs(p -> rs);
}

void postDfs(nptr p) {
    if(p == NULL)
        return ;
   	postDfs(p -> ls);
    postDfs(p -> rs);
    printf("%c ", p -> i);
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

void initQueue() {
    front = 0;
    rear = -1;
}

void bfs() {
    initQueue();
    enqueue(root);
    while(!isEmpty()) {
        nptr p = dequeue();
        printf("%c ", p -> i);
        if(p -> ls != NULL)
            enqueue(p -> ls);
        if(p -> rs != NULL)
            enqueue(p -> rs);
    }
}

int main() {
    nptr a = getNode('A');
    nptr b = getNode('B');
    nptr c = getNode('C');
    nptr d = getNode('D');
    nptr e = getNode('E');  
    nptr f = getNode('F');
    nptr g = getNode('G');
    nptr i = getNode('I');
    nptr j = getNode('J');

    root = a;
    a -> ls = b;
    a -> rs = c;
    b -> ls = d;
    b -> rs = e;
    c -> ls = f;
    c -> rs = g;
    e -> ls = j;
    g -> rs = i;

    inDfs(root);
    printf("\n");
    preDfs(root);
    printf("\n");
    postDfs(root);
    printf("\n");
    bfs();

    return 0;
}