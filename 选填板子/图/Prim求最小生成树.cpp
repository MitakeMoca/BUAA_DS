/*
    给出一个无向、无自环、无重边的无向连通图，用 Prim 算法求它的最小生成树
    输入：第一行输入两个数，第一个表示图上点的个数 n （点的编号从 0 到 n - 1），第二个表示图上边的个数 m ；
        第二行一个整数，表示第一个加入最小生成树的点；
        后面 m 行，每行代表一条边，四个数字，分别表示边的编号，两个端点编号，边的权重
    输出：第一行一个权重，表示最小生成树的权重；第二行从 n - 1 个整数，表示选取边的编号，按加入最小生成树的顺序给出

    示例输入：
        6 10
        0
        1 0 1 600
        2 0 2 100
        3 0 3 500
        4 1 2 500
        5 2 3 500
        6 1 4 300
        7 2 4 600
        8 2 5 400
        9 3 5 200
        10 4 5 600

    示例输出：
        1500
        2 8 9 4 6

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int INF = 0x3f3f3f3f;

int readInt() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

typedef struct node  node;
typedef struct node* nptr;

struct node {
    int id;
    int v;
    int weight;
    nptr next;
};

int vis[10005];
int dis[10005];
int from[10005];    // 记录每个点分别是由哪条边加入的最小生成树
int ans[10005]; // 记录用来构建最小生成树的边集
nptr head[10005];

nptr newnode() { return (nptr)malloc(sizeof(node)); }
nptr getnode(int id, int v, int weight) {
    nptr p = newnode();
    p -> id = id;
    p -> v = v;
    p -> weight = weight;
    p -> next = NULL;
    return p;
}

void addedge(int id, int u, int v, int weight) {
    nptr e = getnode(id, v, weight);
    e -> next = head[u];
    head[u] = e;
}

int main() {
    int n = readInt(), m = readInt(), cnt = 0;    // cnt 表示加入最小生成树边的个数
    int totalWeight = 0;
    int sta = readInt();
    
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
        int tem = -1, minDis = INF;    // 表示当前选择的距离最短的点和最短距离
        for(int j = 0; j < n ;j++)
            if(dis[j] < minDis && !vis[j])
                minDis = dis[j], tem = j;
        ans[cnt++] = from[tem];
        vis[tem] = 1;
        totalWeight += minDis;

        for(nptr p = head[tem]; p ; p = p -> next) 
            if(!vis[p -> v] && dis[p -> v] > p -> weight)
                dis[p -> v] = p -> weight, from[p -> v] = p -> id;
    }

    printf("%d\n", totalWeight);
    for(int i = 1; i < n ;i++)
        printf("%d ", ans[i]);

    return 0;
}