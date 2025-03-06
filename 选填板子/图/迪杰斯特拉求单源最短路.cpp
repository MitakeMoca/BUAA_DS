/*
    给出一个有向无环图，求指定原点到指定终点的最短路
    输入：第一行输入两个数，第一个表示图上点的个数 n （点的编号从 1 到 n），第二个表示图上边的个数 m ；
        第二行输入两个数字，表示起点和终点编号
        后面 m 行，每行代表一条边，三个数字，第一个数字代表边的起点，第二个数字代表边的终点，第三个代表边的权重
    输出：第一行一个整数，代表最短路长度；
        第二行输出从起点到终点经过的所有顶点的编号，若有多种最优方案输出数字字典序最小的一个

    示例输入：
        7 10
        1 7
        1 2 3
        1 3 2
        1 4 3
        2 3 3
        2 5 1 
        3 5 3
        6 3 1
        4 6 3
        5 7 1
        6 7 5

    示例输出：
        5
        1 2 5 7

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int read() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

const int INF = 0x3f3f3f3f;

typedef struct node  node;
typedef struct node* nptr;

struct node {
    int v;
    int weight;
    nptr next;
};
nptr head[10005];      // 邻接表数组
int from[10005];   // 每个点被谁更新
int dis[10005];     // 每个点的最短距离
int vis[10005];     // 每个点是否被访问
int road[10005];    // 记录从起点到终点的路径

nptr newnode() { return (nptr)malloc(sizeof(node)); }
nptr getnode(int v, int weight) {
    nptr p = newnode();
    p -> v = v;
    p -> weight = weight;
    p -> next = NULL;
    return p;
}

void addedge(int u, int v, int weight) {
    nptr p = getnode(v, weight);
    p -> next = head[u];
    head[u] = p;
}

int main() {
    int n = read(), m = read();
    int sta = read(), end = read();

    for(int i = 0; i < m ;i++) {
        int u = read(), v = read(), weight = read();
        addedge(u, v, weight);  // 单向边
    }

    for(int i = 1; i <= n ;i++)
        if(i != sta)
            dis[i] = INF;

    for(int i = 1; i <= n ;i++) {
        int tem = -1, minDis = INF;
        for(int j = 1; j <= n ;j++)
            if(!vis[j] && dis[j] < minDis)
                minDis = dis[j], tem = j;
        
        vis[tem] = 1;
        for(nptr p = head[tem]; p ; p = p -> next)
            if(!vis[p -> v] && p -> weight + dis[tem] < dis[p -> v])
                dis[p -> v] = p -> weight + dis[tem], from[p -> v] = tem;
    }

    printf("%d\n", dis[end]);

    int tem = end, cnt = 0;
    while(tem) {
        road[++cnt] = tem;
        tem = from[tem];
    }

    for(int j = cnt; j > 0 ;j--)
        printf("%d ", road[j]);

    return 0;
}