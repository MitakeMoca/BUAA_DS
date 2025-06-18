#include <stdio.h>
#include <stdlib.h>

int read() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

typedef struct student  student;
struct student {
    char name[25];
    int id, time;
};

student b[105];

int cmp(const void *a, const void *b) {
    student x = *(student *)a;
    student y = *(student *)b;
    if(x.time != y.time)
        return x.time - y.time;
    return x.id - y.id;
}

int main() {
    // m 表示数组 b 已经存了多少元素
    int n = read(), m = 0;

    for(int i = 1; i <= n; i++) {
        student x;
        scanf("%s%d%d", x.name, &x.id, &x.time);

        int vis = 0;
        for(int i = 0; i < m; i++) 
            if(b[i].id == x.id) {
                b[i].time += x.time;
                vis = 1;
                break;
            }
            
        if(vis == 0) 
            b[m++] = x;
    }

    qsort(b, m, sizeof(b[0]), cmp);

    for(int i = 0; i < m; i++)
        printf("%s %08d %d\n", b[i].name, b[i].id, b[i].time);

    return 0;
}