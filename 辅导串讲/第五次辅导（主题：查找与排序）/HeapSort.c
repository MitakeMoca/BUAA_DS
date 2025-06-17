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

// 利用数组 a[0 ~ n - 1] 模拟完全二叉树
// i 的两个儿子分别是 2 * i + 1 和 2 * i + 2
// i 的父亲是 (i - 1) / 2
void up(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        // 满足堆性质，不再调整
        if (a[parent] >= a[i]) break;  
        swap(&a[parent], &a[i]);
        // 继续向上调整
        i = parent;  
    }
}

void down(int i, int n) {
    int j = 2 * i + 1;
    // 至少要有左儿子
    while (j < n) {
        // 如果有右儿子，且右儿子更大，选右儿子
        if (j + 1 < n && a[j] < a[j + 1])
            j++;
        // 满足堆性质，不用再调整了
        if (a[i] >= a[j])
            break;
        // 交换父子节点
        swap(&a[i], &a[j]); 
        // 继续向下调整
        i = j;                 
        j = 2 * i + 1;
    }
}

int main() {
    int n = readInt();

    // 边读入边维护堆
    for(int i = 0; i < n ;i++)
        a[i] = readInt(), up(i);

    // 先将第一个元素和已经排好的元素前一位做交换，再重新调整（刚调整的元素之前的元素），直到排序完毕
    for (int i = n - 1; i > 0; i--) {
        swap(&a[0], &a[i]);
        down(0, i);
    }

    for(int i = 0; i < n ;i++)
        printf("%d ", a[i]);

    return 0;
}