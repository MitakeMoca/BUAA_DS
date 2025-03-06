/*
    给定叶子结点的权，求哈夫曼树的带权路径长度
    输入：第一行一个整数 n，表示叶子结点的个数；第二行 n 个整数表示各个节点的权
    输出：一个整数表示带权路径长度

    示例输入：
        5
        3 9 6 2 5

    示例输出：
        55
*/

#include <stdio.h>

int read() {
    int tem;
    scanf("%d", &tem);
    return tem;
}

int heap[10005];
int n;

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

// 维护一个小顶堆
void adjust(int i, int n) {
    int j = 2 * i + 1, temp = heap[i];

    while (j < n) {
        if (j < n - 1 && heap[j] > heap[j + 1])
            j++;
        if (temp <= heap[j])
            break;
        heap[(j - 1) / 2] = heap[j];
        j = 2 * j + 1;
    }
    heap[(j - 1) / 2] = temp;
}

int pop() {
    int min = heap[0];
    heap[0] = heap[--n];
    adjust(0, n);
    return min;
}

void push(int x, int n) {
    int i = n - 1;
    while (i > 0 && heap[(i - 1) / 2] > x) {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap[i] = x;
}

int main() {
    n = read();

    for (int i = 0; i < n; i++)
        heap[i] = read();

    // 数组 -> 堆 的初始化操作
    for (int i = (n - 1 - 1) / 2; i >= 0; i--)
        adjust(i, n);

    int ans = 0;

    while (n > 1) {
        int min1 = pop();
        int min2 = pop();
        int sum = min1 + min2;
        ans += sum;
        push(sum, ++n);
    }

    printf("%d\n", ans);

    return 0;
}
