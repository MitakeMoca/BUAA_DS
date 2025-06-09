#include <stdio.h>
#include <stdlib.h>

typedef struct node  node;
typedef struct node* nptr;

struct node {
    int val;
    nptr nxt;
};

nptr newnode() {
    return (nptr)malloc(sizeof(node));
}

nptr getnode(int val) {
    nptr p = newnode();
    p -> val = val;
    p -> nxt = NULL;
    return p;
}

nptr e[9];
// 添加有向边 (u, v)
void add_edge(int u, int v) {
    nptr p = getnode(v);
    p -> nxt = e[u];
    e[u] = p;
}

int vis[9];
void dfs(int u) {
    printf("%d ", u);
    vis[u] = 1;
    for (nptr p = e[u]; p != NULL; p = p -> nxt) {
        int v = p -> val;
        if (!vis[v]) dfs(v);
    }
}

int main() {
    // 在无向图中，你也可以把 add_edge 改成双向边版本
    add_edge(0, 1);add_edge(1, 0);
    add_edge(0, 2);add_edge(2, 0);
    add_edge(1, 3);add_edge(3, 1);
    add_edge(1, 4);add_edge(4, 1);
    add_edge(1, 8);add_edge(8, 1);
    add_edge(2, 5);add_edge(5, 2);
    add_edge(2, 7);add_edge(7, 2);
    add_edge(3, 6);add_edge(6, 3);
    add_edge(5, 7);add_edge(7, 5);
    add_edge(6, 8);add_edge(8, 6);
    dfs(0);
    return 0;
}