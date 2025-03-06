/*
    已知某序列是大顶堆，在序列尾部插入新元素 x ，将其再调整为大顶堆。输出调整过程中元素之间进行的比较次数
    输入：第一行一个整数 n，表示大顶堆中元素的个数；第二行 n 个整数，表示大顶堆中的元素；
        第三行一个整数 x，表示新插入的元素
    输出：一个整数，表示调整过程中元素之间进行的比较次数

    示例输入：
        5
        25 13 10 12 9
        18

    示例输出：
        2
*/

#include <stdio.h>

int read() {
    int tem;
    scanf("%d", &tem);
    return tem;
}

int heap[10005];

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main() {
    int n = read();
    for (int i = 0; i < n; i++)
        heap[i] = read();

    int x = read();
    heap[n] = x;
    n++;

    int ans = 0;
    int i = n - 1;
    // 向上调整大顶堆
    while (i > 0) {
        int parent = (i - 1) / 2;
        ans++;
        if (heap[i] > heap[parent]) {
            swap(&heap[i], &heap[parent]);
            i = parent;
        } else {
            break;
        }
    }

    printf("%d\n", ans);
    return 0;
}
