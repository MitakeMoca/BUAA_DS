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
    int val;
    int dep;
    nptr ls, rs;
};
nptr root;

nptr newnode() {
    return (nptr)malloc(sizeof(node));
}

nptr getnode(int val, int dep) {
    nptr p = newnode();
    p -> val = val;
    p -> dep = dep;
    p -> ls = NULL;
    p -> rs = NULL;
    return p;
}

void insert(nptr p, int val) {
    if(val < p -> val) {
        if(p -> ls == NULL) {
            p -> ls = getnode(val, p -> dep + 1);
            return;
        } else
            insert(p -> ls, val);
    } else {
        if(p -> rs == NULL) {
            p -> rs = getnode(val, p -> dep + 1);
            return;
        } else
            insert(p -> rs, val);
    }
}

void inDfs(nptr p) {
    if(p == NULL) return;
    inDfs(p -> ls);
    if (p -> ls == NULL && p -> rs == NULL)
        printf("%d %d\n", p -> val, p -> dep);
    inDfs(p -> rs);
}

int main() {
    int n = readInt();
    for(int i = 1; i <= n; i++) {
        if(root == NULL) {
            root = getnode(readInt(), 1);
            continue;
        } else
            insert(root, readInt());
    }

    inDfs(root);
    return 0;
}