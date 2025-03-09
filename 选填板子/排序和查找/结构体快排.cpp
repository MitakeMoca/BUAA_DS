/*
    结构体排序，先按学生名字字典序排序；当学生名字相同时，按照 id 从小到大排序

    输入：
        第一行一个整数 n，表示学生数目
        接下来 n 行，每行一个整数和一个字符串（不带空格），表示学生 id 和姓名
    输出：
        n 行，每行输出学生 id 和 name

    示例输入：
        5
        1 moca
        2 ran
        3 tsugu
        4 moca
        5 lisi

    示例输出：
        5 lisi
        1 moca
        4 moca
        2 ran
        3 tsugu
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int read() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

typedef struct student student;
struct student {
    char name[15];
    int id;
};

student a[20];

int cmp(const void *a, const void *b) {
    student x = *(student *)a;
    student y = *(student *)b;
    if(strcmp(x.name, y.name))
        return strcmp(x.name, y.name);
    return x.id - y.id;
}

int main() {
    int n = read();
    for(int i = 1; i <= n; i++)
        a[i].id = read(), scanf("%s", a[i].name);

    qsort(a + 1, n, sizeof(a[0]), cmp);
    for(int i = 1; i <= n; i++)
        printf("%d %s\n", a[i].id, a[i].name);
    return 0;
}
