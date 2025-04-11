#include <stdio.h>
#include <string.h>

char num[105];

int read() {
    int tem;
    scanf("%d", &tem);
    return tem;
}

int main() {
    scanf("%s", num);
    int pos1 = -1, pos2 = 0; // 记录第一个不为 0 数字的位置和小数点的位置

    int len = strlen(num);
    for(int i = 0; i < len; i++) {
        if(pos1 == -1 && num[i] != '0' && num[i] != '.') pos1 = i;
        if(num[i] == '.')   pos2 = i;
    }

    printf("%c", num[pos1]);
    if(pos1 != len - 1) printf(".");
    for(int i = pos1 + 1; i < len; i++)
        if(num[i] != '.')   printf("%c", num[i]);
    
    printf("e%d",pos2 - pos1 > 0 ? pos2 - pos1 - 1 : pos2 - pos1);

    return 0;
}