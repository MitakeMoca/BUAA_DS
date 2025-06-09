#include <stdio.h>
#include <stdlib.h>

const int INF = 0x3f3f3f3f;

int readInt() {
    int tem;
    scanf("%d", &tem);
    return tem;
}

typedef struct node  node;
typedef struct node* nptr;

struct node {
    int id, v, weight;
    nptr nxt;
};

int vis[10005], dis[10005];
int from[10005];    // 记录每个点分别是由哪条边加入的最小生成树
int ans[10005]; // 记录用来构建最小生成树的边集
nptr head[10005];

nptr newnode() { 
    return (nptr)malloc(sizeof(node)); 
}

nptr getnode(int id, int v, int weight) {
    nptr p = newnode();
    p -> id = id;
    p -> v = v;
    p -> weight = weight;
    p -> nxt = NULL;
    return p;
}

// 建立双向边
nptr addedge(int id, int u, int v, int weight) {
    nptr e = getnode(id, v, weight);
    e -> nxt = head[u];
    head[u] = e;
}

int int_cmp(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return x - y;
}

int main() {
    int n = readInt(), m = readInt(), cnt = 0;    // cnt 表示加入最小生成树边的个数
    int total = 0, sta = 0;
    
    for(int i = 0; i < n ;i++)
        if(i != sta)
            dis[i] = INF;

    for(int i = 0; i < m ;i++) {
        int id = readInt(), u = readInt(), v = readInt(), weight = readInt();
        addedge(id, u, v, weight);
        addedge(id, v, u, weight);
    }

    // 每次选择一个距离最小的点加入最小生成树的点集
    for(int i = 0; i < n ;i++) {
        int tem = -1, min_dis = INF;    // 表示当前选择的距离最短的点和最短距离
        for(int j = 0; j < n ;j++)
            if(dis[j] < min_dis && !vis[j])
                min_dis = dis[j], tem = j;
        ans[cnt++] = from[tem];
        vis[tem] = 1;
        total += min_dis;

        for(nptr p = head[tem]; p ; p = p -> nxt) 
            if(!vis[p -> v] && dis[p -> v] > p -> weight)
                dis[p -> v] = p -> weight, from[p -> v] = p -> id;
    }

    qsort(ans + 1, n - 1, sizeof(ans[0]), int_cmp);
    printf("%d\n", total);
    for(int i = 1; i < n; i++)
        printf("%d ", ans[i]);

    return 0;
}