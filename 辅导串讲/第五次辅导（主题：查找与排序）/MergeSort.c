#include <stdio.h>
#include <string.h>

int readInt() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

int a[100005];
int tem[100005];

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void merge(int l, int r) {
    int mid = (l + r) >> 1;	// 根据优先级，括号不写也行
    int i = l, j = mid + 1; // 两端的开始和结束
    int k = l;
    while((i <= mid) || (j <= r)) {	// 合并
        if(j > r || (i <= mid && a[i] <= a[j])) {
            // 如果右子列空了或者左子列当前元素小于右子列当前元素，新的位是左面第一位，且计算逆序对数
            tem[k++] = a[i++];
        }
        else {// 否则，新的位是右面第一位
            tem[k++] = a[j++];
        }
    }
    
    for(int i = l;i <= r;i++) {
        a[i] = tem[i];    // 归还排好序的段
    }
        
}

void mergeSort(int l, int r) {
    int mid = (l + r) >> 1; // 根据优先级，括号不写也行
    
    // 内部开销和合并开销
    if(l < r) {
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
        merge(l, r);
    }
}

int main() {
    int n = readInt();

    for(int i = 1; i <= n ;i++)
        a[i] = readInt();

    mergeSort(1, n);

    for(int i = 1; i <= n ;i++)
        printf("%d ", a[i]);

    return 0;
}