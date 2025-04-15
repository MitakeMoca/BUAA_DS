#include <stdio.h>

int readInt() {
    int tem;
    scanf("%d", &tem);
    return tem;
}

int n, a[55][55];

void dfs(int i, int j) {
    // 越界检查以及检查该点是否到达过
    if(i < 0 || j < 0 || i > n || j > n || a[i][j])
        return ;
    a[i][j] = 2;
    // 向四个方向洪泛
    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
    return ;
}

int main() {
    n = readInt();
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            a[i][j] = readInt();

    // 从 (0, 0) 开始出发
    dfs(0, 0);

    int ans = 0;
    // 统计仍为 0 的数字个数
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(a[i][j] == 0)
                ans++;
    printf("%d", ans);

    return 0;
}


