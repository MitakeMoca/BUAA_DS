#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int read() {
    int tem;
    scanf("%d", &tem);
    return tem;
}

int a[10005];

int bsearch(int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) >> 1;

        if (a[mid] == target)
            return mid;
        if (a[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int cmp(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return x - y;
}

int main() {
    int n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();

    qsort(a + 1, n, sizeof(a[0]), cmp);

    int target = read();

    printf("%d", bsearch(1, n, target));

    return 0;
}
