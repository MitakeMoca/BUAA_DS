#include <stdio.h>
#include <string.h>

// 文件读写的前提是输入文件存在

int readInt() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

int a[105];

int main() {
    freopen("in.txt", "rb", stdin);
    int n;

    // 假设先从文件中读入 n，再读入 n 个整数
    n = readInt();
    for(int i = 1; i <= n ;i++)
        scanf("%d", &a[i]);

    // 再将 n 个整数输出到文件中
    freopen("out.txt", "wb", stdout);
    for(int i = 1; i <= n ;i++)
        printf("%d\n", a[i]);

    return 0;
}