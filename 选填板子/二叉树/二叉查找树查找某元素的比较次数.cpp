/*
    采用逐点插入法建立某序列的二叉查找树后, 查找数据元素 x 共进行多少次元素间的比较
    输入：第一行一个整数 n，表示二叉查找树的元素个数；第二行 n 个整数，表示用来建立二叉查找树的元素；
        第三行一个整数 x，表示要被查找的元素
    输出：一个整数，表示查找 x 进行的比较次数

    示例输入：
        10
        54 28 16 34 73 62 95 60 26 43
        62

    示例输出：
        3
*/

#include <stdio.h>
#include <string.h>

int readInt() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

int a[10005];   // 表示树
int vis[10005]; // 标记树上有没有结点

void insert(int i) {
    int tem = 0;
    while(vis[tem]) {
        if(i < a[tem])
            tem = tem * 2 + 1;
        else
            tem = tem * 2 + 2;
    }
    a[tem] = i;
    vis[tem] = 1;
}

int main() {
    int n = readInt();
    for(int i = 0; i < n ;i++) 
        insert(readInt());

    int x = readInt();
    int tem = 0, cnt = 0;
    while(vis[tem]) {
        cnt++;
        if(x < a[tem])
            tem = tem * 2 + 1;
        else if(x == a[tem])
            break;
        else
            tem = tem * 2 + 2;
    }

    printf("%d", cnt);
    return 0;
}