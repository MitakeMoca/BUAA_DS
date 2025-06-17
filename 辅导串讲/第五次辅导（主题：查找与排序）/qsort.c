#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int readInt()
{
    int tem;
    scanf("%d", &tem);
    return tem;
}

int a[10005];

typedef struct student student;
struct student
{
    char name[15];
    int id;
};

student a[20];

int cmp(const void *a, const void *b)
{
    student x = *(student *)a;
    student y = *(student *)b;
    return strcmp(x.name, y.name);
}

int main()
{
    int n = readInt();
    for (int i = 1; i <= n; i++)
        a[i] = readInt();

    qsort(a + 1, n, sizeof(a[0]), cmp);
    return 0;
}