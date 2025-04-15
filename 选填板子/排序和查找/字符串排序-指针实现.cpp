/*
    对给定的字符串进行字典序排序
    输入：第一行一个整数 n，表示字符串的个数；
        后面 n 行，每行一个字符串，表示待排序的字符串
    输出：n 行，表示排序后的字符串

    示例输入：
        5
        orange
        banana
        undefined
        apple
        otter

    示例输出：
        apple
        banana
        orange
        otter
        undefined

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int readInt() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

char* str[1005];
char tem[1005];
int cmp(const void *a, const void *b) {
    char *x = *(char **)a;
    char *y = *(char **)b;
    return strcmp(x, y);
}

int main() {
    int n = readInt();
    for(int i = 0; i < n ;i++) {
        scanf(" %s", tem);
        str[i] = (char *)malloc(strlen(tem) + 1);
        strcpy(str[i], tem);
    }

    qsort(str, n, sizeof(str[0]), cmp);
    for(int i = 0; i < n ;i++)
        puts(str[i]);
    return 0;
}