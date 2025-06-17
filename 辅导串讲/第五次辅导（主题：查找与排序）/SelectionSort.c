#include <stdio.h>
#include <string.h>

int readInt() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

int a[100001];

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main() {
    int n = readInt();

    for(int i = 1; i <= n ;i++)
        a[i] = readInt();
    
    // 排序过程最多执行 n - 1 次
    for (int i = 1; i < n; ++i) {
        // ith 代表最小的元素的下标
        int ith = i;
        for (int j = i + 1; j <= n; ++j) 
            if (a[j] < a[ith]) {
                ith = j;
            }
        // 将最小的元素与未排序部分的第一个元素交换
        swap(&a[i], &a[ith]);
    }

    for(int i = 1; i <= n ;i++)
        printf("%d ", a[i]);

    return 0;
}