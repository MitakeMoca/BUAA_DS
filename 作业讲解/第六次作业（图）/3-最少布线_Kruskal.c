#include <stdio.h>
#include <stdlib.h>

int readInt() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

typedef struct edge  edge;
struct edge {
    int id, u, v, weight;
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

int edge_cmp(const void *a, const void *b) {
    edge x = *(edge *)a;
    edge y = *(edge *)b;
    if(x.weight - y.weight)
        return x.weight - y.weight;
    return x.id - y.id;
}

int int_cmp(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return x - y;
}

int main() {
    int n = readInt(), m = readInt();
    for(int i = 0; i < m; i++) 
        e[i].id = readInt(), e[i].u = readInt(), e[i].v = readInt(), e[i].weight = readInt();
    qsort(e, m, sizeof(e[0]), edge_cmp);
    int total = 0, cnt = 0;

    // 并查集初始化
    for(int i = 0; i < n; i++)   
        f[i] = i;

    for(int i = 0; i < m; i++) {
        if(find(e[i].u) != find(e[i].v))
            ans[++cnt] = e[i].id, total += e[i].weight, link(e[i].u, e[i].v);
    }

    qsort(ans + 1, cnt, sizeof(ans[0]), int_cmp);
    printf("%d\n", total);
    for(int i = 1; i < n ;i++)
        printf("%d ", ans[i]);
    return 0;
}