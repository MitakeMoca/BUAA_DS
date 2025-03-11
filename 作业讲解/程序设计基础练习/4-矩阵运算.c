#include <stdio.h>

int a[15][15];

int read() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

int main() {
    int n = read();
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            a[i][j] = read();
    
    // 在 %c 前面加空格可以忽略所有空格和换行符
    char op;
    scanf(" %c", &op);

    while(op != '#') {
        // 如果 op 是 +，那么 tem = 1；如果 op 是 -，那么 tem = -1
        // 以此我们就能把下面的 +- 操作统一成 + 操作
        int tem = op == '+' ? 1 : -1;

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                a[i][j] += tem * read();

        // 读入新的操作符
        scanf(" %c", &op);
    }

    for(int i = 1; i <= n; i++) {
        // "%5d" 已经是 5 位了，不要再写 "%5d " 了
        for(int j = 1; j <= n; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }

    return 0;
}