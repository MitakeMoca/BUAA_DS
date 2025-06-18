#include <stdio.h>

int read() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int a[105], cmp_cnt = 0;
void selection_sort(int n) {
    for (int i = 0; i < n - 1; i++) {
        // ith 代表最小的元素的下标
        int ith = i;
        for (int j = i + 1; j < n; j++) {
            cmp_cnt++;
            if (a[j] < a[ith]) 
                ith = j;
        }
        // 将最小的元素与未排序部分的第一个元素交换
        swap(&a[i], &a[ith]);
    }
}

void bubble_sort(int n) {
    for (int i = 1; i <= n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i; j++) {
            cmp_cnt++;
            if (a[j] > a[j + 1]) {
                swapped = 1;
                swap(&a[j], &a[j + 1]);
            }
        }
        if (!swapped) break;  // 提前退出
    }
}

void adjust(int k[], int i, int n) {
    int j, temp;
    temp = k[i];
    j = 2 * i + 1;
    while(j < n) {
        if(j < n - 1 && k[j] < k[j + 1])
            j++;
        cmp_cnt++;
        if(temp >= k[j]) 
            break;
        k[(j - 1) / 2] = k[j];
        j = 2 * j + 1;
    }
    k[(j - 1) / 2] = temp;
}

void heap_sort(int n) {
    for(int i = n / 2 - 1; i >= 0; i--)
	    adjust(a, i, n);
    for (int i = n - 1; i > 0; i--) {
        swap(&a[0], &a[i]);
        adjust(a, 0, i);
    }
}

int tem[105];
void merge(int l, int mid, int r) {
	int i = l, j = mid + 1, q = l;
	while (i <= mid && j <= r) {
        cmp_cnt++;
		if (a[i] <= a[j])
			tem[q++] = a[i++];
		else
            tem[q++] = a[j++];
	}
	while (i <= mid)
		tem[q++] = a[i++];
	while (j <= r)
		tem[q++] = a[j++];
	for (i = l; i <= r; i++)
		a[i] = tem[i];
}

void merge_sort(int l, int r) {
    int mid = (l + r) >> 1;
    if(l < r) {
        // 先对前后两部分排序
        merge_sort(l, mid);
        merge_sort(mid + 1, r);
        // 合并两个有序数组
        merge(l, mid, r);
    }
}

void quick_sort(int l, int r) {
    int i, last;
    if (l < r) {
        last = l;
        for (i = l + 1; i <= r; i++) {
            cmp_cnt++;
           if (a[i] < a[l])
                swap(&a[++last], &a[i]); 
        }
            
        swap(&a[l], &a[last]);
        quick_sort(l, last - 1);
        quick_sort(last + 1, r);
    }
}

int main() {
    int n = read(), method = read();
    for(int i = 0; i < n; i++)
        a[i] = read();
    if(method == 1)
        selection_sort(n);
    else if(method == 2)
        bubble_sort(n);
    else if(method == 3)
        heap_sort(n);
    else if(method == 4)
        merge_sort(0, n - 1);
    else 
        quick_sort(0, n - 1);
    
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n%d", cmp_cnt);
    return 0;
}