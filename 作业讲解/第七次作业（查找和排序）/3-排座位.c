#include <stdio.h>
#include <stdlib.h>

int read() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

typedef struct student student;
struct student {
    int id, seat;
    char name[25];
};
student a[105];

int cmp(const void *a, const void *b) {
    student x = *(student *)a;
    student y = *(student *)b;
    if(x.seat != y.seat)
        return x.seat - y.seat;
    return x.id - y.id;
}

int cmp2(const void *a, const void *b) {
    student x = *(student *)a;
    student y = *(student *)b;
    return x.id - y.id;
}

int vis[105];

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n = read();
    // 在控制台读入 n 后，只有一个文件的输入，用 freopen 最简单
    freopen("in.txt", "rb", stdin);
    freopen("out.txt", "wb", stdout);
    // vis 统计每个座位号出现了多少次
    for(int i = 1; i <= n; i++)
        scanf("%d%s%d", &a[i].id, a[i].name, &a[i].seat), vis[a[i].seat]++;
    qsort(a + 1, n, sizeof(a[0]), cmp);

    int q = min(a[n].seat, n), end = n;
    for(int i = 1; i <= q; i++) {
        // 这个座位号没有人
        if(vis[i] == 0) {
            vis[a[end].seat]--;
            a[end].seat = i;
            end--;
            q = min(a[end].seat, n);
        }
    }
    
    qsort(a + 1, n, sizeof(a[0]), cmp);
    int m = a[n].seat;
    for(int i = 2; i <= n; i++)
        if(a[i].seat == a[i - 1].seat)
            a[i].seat = ++m;
    
    qsort(a + 1, n, sizeof(a[0]), cmp2);
    for(int i = 1; i <= n; i++)
        printf("%d %s %d\n", a[i].id, a[i].name, a[i].seat);
    return 0;
}