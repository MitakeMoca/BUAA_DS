#include <stdio.h>

int readInt() {
    int tem;
    scanf("%d", &tem);
    return tem;
}

char num_to_alpha(int i) {
    if(i < 10)
        return i + '0';
    // 否则就是字母
    // 10 -> a, 11 -> b, ...
    return i + 'a' - 10;
}

int output[105];
int main() {
    int n = readInt(), b = readInt();
    int flag = 0;
    // 特判一下 0，大家可以试试如果没写这一行可能有什么后果
    if(n == 0) {
        printf("0");
        return 0;
    }
    
    if(n < 0)
        n = -n, flag = 1;
    // 记录 output 用到了第几位
    int cnt = 0;
    // 不断取余取商
    while(n) {
        output[++cnt] = n % b;
        n /= b;
    }
    // 先输出负号
    if(flag)
        printf("-");
    // 再倒序输出每一位
    for(int i = cnt; i > 0; i--)
        printf("%c", num_to_alpha(output[i]));
    return 0;
}