#include <stdio.h>
int e[105][105];
int vis[105];

int readInt() {
    int tem;
    scanf("%d", &tem);
    return tem;
}

int n, m;
void dfs(int u) {
    // 标记为已访问
    printf("%d ", u);
    vis[u] = 1;
    // 遍历所有顶点
    for (int v = 0; v < n; v++) { 
        // 如果有边且未访问
        if (e[u][v] && !vis[v])  
            dfs(v);
    }
}

// 为了大家看着方便，我们就不把队的基本操作封装了
int que[1005];
void bfs(int u) {
    int front = 0, rear = -1;
    que[++rear] = u;
    while (front <= rear) {
        int tem = que[front++];
        if(vis[tem] == 1)
            continue;
        vis[tem] = 1;
        printf("%d ", tem);
        for (int v = 0; v < n; v++) 
            if (e[tem][v] && !vis[v]) 
                que[++rear] = v;
    }
}

void clear_vis() {
    for (int i = 0; i < n; i++) vis[i] = 0;
}

int main() {
    n = readInt(), m = readInt();
    for (int i = 0; i < m; i++) {
        int a = readInt(), b = readInt();
        e[a][b] = e[b][a] = 1;
    }
    int del = readInt();

    // 从 0 开始遍历
    dfs(0);printf("\n");clear_vis();
    bfs(0);printf("\n");clear_vis();
    vis[del] = 1;dfs(0);printf("\n");clear_vis();
    vis[del] = 1;bfs(0);printf("\n");clear_vis();
    return 0;
}