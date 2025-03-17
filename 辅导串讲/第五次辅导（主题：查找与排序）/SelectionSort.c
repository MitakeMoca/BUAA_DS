#include <stdio.h>
#include <string.h>

int read() {
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
    int n = read();

    for(int i = 1; i <= n ;i++)
        a[i] = read();
    
    // 排序过程最多执行 n - 1 次
    for (int i = 1; i < n; ++i) {
        int ith = i;
        for (int j = i + 1; j <= n; ++j) {
            if (a[j] < a[ith]) {
                ith = j;
            }
        }
        swap(&a[i], &a[ith]);
    }

    for(int i = 1; i <= n ;i++)
        printf("%d ", a[i]);

    return 0;
}