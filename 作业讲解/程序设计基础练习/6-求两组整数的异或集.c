#include <stdio.h>
#include <stdlib.h>

// del 数组用来标记第 i 个数是否被删除
int a[10005], del[10005];

int cmp(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    // 注意这里可能存在的溢出问题
    return y - x;
}

int main() {
    int cnt = 0;
    int num = 0;
    while(scanf("%d", &num) != EOF)
        a[++cnt] = num;
    qsort(a + 1, cnt, sizeof(int), cmp);

    // 排序完成，开始查重
    for(int i = 1; i <= cnt; i++)
        for(int j = i + 1; j <= cnt; j++)
            if(a[i] == a[j])
                del[i] = del[j] = 1;

    for(int i = 1; i <= cnt; i++)
        if(del[i] == 0)
            printf("%d ", a[i]);

    printf("\n");
}