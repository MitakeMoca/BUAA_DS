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

    for (int i = 2; i <= n; ++i) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    for(int i = 1; i <= n ;i++)
        printf("%d ", a[i]);

    return 0;
}