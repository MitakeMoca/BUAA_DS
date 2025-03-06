/*
    将若干数据元素依次存放于一个一维数组中，然后采用折半查找方法查找元素12，输出被比较过的数组元素的下标
    输入：第一行一个整数 n，表示数组中元素的个数；第二行 n 个整数，表示数组中的元素；
        第三行一个整数 x，表示要被查找的元素
    输出：被比较过的数组元素的下标

    示例输入：
        10
        2 4 6 8 10 12 14 16 18 20
        12

    示例输出：
        4 7 5
*/

#include <stdio.h>
#include <string.h>

int read() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

int a[10005];

int main() {
    int n = read();
    for(int i = 0; i < n ;i++)
        a[i] = read();

    int x = read();
    int l = 0, r = n - 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        printf("%d ", mid);
        if(a[mid] < x)
            l = mid + 1;
        else if(a[mid] == x)
            break;
        else
            r = mid - 1;
    }
    return 0;
}