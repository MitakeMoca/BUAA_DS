/*
    堆排序中，用关键字序列创建初始大顶堆，得到的初始大顶堆是什么

    输入：
        第一行一个整数 n，表示数字个数
        接下来一行输入 n 个整数，用一个空格分隔，表示排序的 n 个数
    输出：
        一行 n 个整数，用一个空格分隔，表示初始大顶堆

    示例输入：
        7
        6 9 1 5 8 4 7

    示例输出：
        9 8 7 5 6 4 1
*/

#include <stdio.h>
#include <string.h>

int readInt() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

int a[100005];

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void adjust(int k[], int i, int n) {
    int j, temp;
    temp = k[i];
    j = 2 * i + 1;
    while(j < n) {
        if(j < n - 1 && k[j] < k[j + 1])
            j++;
        if(temp >= k[j]) 
            break;
        k[(j - 1) / 2] = k[j];
        j = 2 * j + 1;
    }
    k[(j - 1) / 2] = temp;
}

int main() {
    int n = readInt();

    for(int i = 0; i < n ;i++)
        a[i] = readInt();
    
    // 维护堆
    for(int i = n / 2 - 1; i >= 0; i--)
	    adjust(a, i, n);

    // 输出初始大顶堆
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}