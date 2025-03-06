/*
    给出一个有向无环图，输出它的拓扑序
    输入：第一行输入两个数，第一个表示图上点的个数 n （点的编号从 1 到 n），第二个表示图上边的个数 m ；
        后面 m 行，每行代表一条边，两个数字，第一个数字代表边的起点，第二个数字代表边的终点
    输出：一行，表示边的拓扑序

    示例输入：
        6 8
        1 2
        1 4
        2 6
        3 1
        3 4
        4 5
        5 2
        5 6

    示例输出：
        3 1 4 5 2 6

*/
#include <stdio.h>
#include <string.h>

int read() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

// 但是我们期末图不考编程，只考选填，就那么几个点，我就拿临接矩阵建图了
int e[1005][1005];
int vis[1005];
int ans[1005];  // 点的拓扑序
int de[1005];   // 点的入度
int cnt, n, m;

void topoLogic(int i) {
    if(vis[i])  
        return;
    vis[i] = 1;
    for(int j = 1; j <= n ;j++) 
        if(e[i][j])
            topoLogic(j);
    ans[++cnt] = i;
}

int main() {
    n = read(), m = read();
    for(int i = 0; i < m ;i++) {
        int u = read(), v = read();
        e[u][v] = 1, de[v]++;
    }

    for(int i = 1; i <= n ;i++) 
        if(de[i] == 0)  
            topoLogic(i);
    
    for(int i = n; i >= 1 ;i--)
        printf("%d ", ans[i]);
    return 0;
}