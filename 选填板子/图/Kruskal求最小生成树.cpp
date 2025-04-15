/*
    给出一个无向、无自环、无重边的无向连通图，用 Kruskal 算法求它的最小生成树
    输入：第一行输入两个数，第一个表示图上点的个数 n （点的编号从 0 到 n - 1），第二个表示图上边的个数 m ；
        后面 m 行，每行代表一条边，四个数字，分别表示边的编号，两个端点编号，边的权重
    输出：第一行一个权重，表示最小生成树的权重；第二行从 n - 1 个整数，表示选取边的编号，按加入最小生成树的顺序给出

    示例输入：
        6 10
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
        2 9 6 8 4

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int readInt() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

typedef struct edge  edge;

struct edge {
    int id;
    int u;
    int v;
    int weight;
};

int f[10005];   // 用来维护并查集
edge e[10005];  // 用来维护所有边
int ans[10005]; // 记录 MST 选择的边

// 查
int find(int i) {
    return f[i] = f[i] == i ? i : find(f[i]);
}

// 并
void link(int u, int v) {
    f[find(u)] = find(v);
}

int cmp(const void *a, const void *b) {
    edge x = *(edge *)a;
    edge y = *(edge *)b;
    return x.weight - y.weight ? x.weight - y.weight : x.id - y.id;
}

int main() {
    int n = readInt(), m = readInt();
    for(int i = 0; i < m ;i++) 
        e[i].id = readInt(), e[i].u = readInt(), e[i].v = readInt(), e[i].weight = readInt();
    qsort(e, m, sizeof(e[0]), cmp);
    int totalWeight = 0, cnt = 0;

    // 并查集初始化
    for(int i = 0; i < n;i++)   
        f[i] = i;

    for(int i = 0; i < m ;i++) {
        if(find(e[i].u) != find(e[i].v))
            ans[++cnt] = e[i].id, totalWeight += e[i].weight, link(e[i].u, e[i].v);
    }

    printf("%d\n", totalWeight);
    for(int i = 1; i < n ;i++)
        printf("%d ", ans[i]);
    return 0;
}