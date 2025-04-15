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
    FILE *in = fopen("in.txt", "rb");
    int n;

    // 假设先从文件中读入 n，再读入 n 个整数
    fscanf(in, "%d", &n);
    for(int i = 1; i <= n ;i++)
        fscanf(in, "%d", &a[i]);

    // 再将 n 个整数输出到文件中
    FILE *out = fopen("out.txt", "wb");
    for(int i = 1; i <= n ;i++)
        fprintf(out, "%d\n", a[i]);

    return 0;
}