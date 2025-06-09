#include <stdio.h>
#include <stdlib.h>

int readInt() {
    int tem;
    scanf("%d", &tem);
    return tem;
}

// 习惯性地我们还是这么命名吧
typedef struct node  node;
typedef struct node* nptr;

struct node {
    int id, to;
    nptr nxt;
};
// 我们还是利用带哨兵结点的链表
nptr head[1005], tail[1005];

nptr newnode() {
    return (nptr)malloc(sizeof(node));
}

nptr getnode(int id, int to) {
    nptr p = newnode();
    p -> id = id;
    p -> to = to;
    p -> nxt = NULL;
    return p;
}

// 插入的时候有序
void add_edge(int id, int u, int v) {
    nptr p = getnode(id, v);
    nptr q = head[u];
    // 因为有哑结点 1005，所以 q -> nxt 一定不为 NULL
    while(q -> nxt -> id < id) 
        q = q -> nxt;
    p -> nxt = q -> nxt;
    q -> nxt = p;
}

// 记录路径上有哪些边，以及路径的长度
int ans[1005], cnt;
// 记录当前路径访问过哪些节点
int vis[1005], n, m;
void dfs(int u) {
    // 到达了终点，输出路径
    if(u == n - 1) {
        for(int i = 0; i < cnt; i++) 
            printf("%d ", ans[i]);
        printf("\n");
        return ;
    }
    vis[u] = 1;
    for(nptr p = head[u] -> nxt; p -> id != 1005; p = p -> nxt) {
        int v = p -> to;
        if(!vis[v]) {
            ans[cnt++] = p -> id;
            dfs(v);
            cnt--;
        }
    }
    // 回溯
    vis[u] = 0;
}

int main () {
    n = readInt(), m = readInt();
    // 初始化邻接表里的每个链表
    for(int i = 0; i <= 1000; i++) {
        head[i] = getnode(-1, -1);
        tail[i] = getnode(1005, -1);
        head[i] -> nxt = tail[i];
    }
    for(int i = 0; i < m; i++) {
        int id = readInt(), u = readInt(), v = readInt();
        // 一定要双向建边
        add_edge(id, u, v);
        add_edge(id, v, u);
    }
    dfs(0);
    return 0;
}