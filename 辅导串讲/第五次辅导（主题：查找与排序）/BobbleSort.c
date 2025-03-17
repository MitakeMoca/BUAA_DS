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

    // 用来记录是否还需要排序
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] > a[i + 1]) {
                flag = 1;
                swap(&a[i], &a[i + 1]);
            }
        }
    }

    for(int i = 1; i <= n ;i++)
        printf("%d ", a[i]);

    return 0;
}