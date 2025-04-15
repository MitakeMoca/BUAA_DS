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

void adjust(int i, int n) {
    int j = 2 * i + 1, temp = a[i];

    while(j < n) {
        if(j < n - 1 && a[j] < a[j + 1])
            j++;
        if(temp >= a[j]) 
            break;
        a[(j - 1) / 2] = a[j];
        j = 2 * j + 1;
    }
    a[(j - 1) / 2] = temp;

}

int main() {
    int n = readInt();

    for(int i = 0; i < n ;i++)
        a[i] = readInt();

    for (int i = (n - 1 - 1) / 2; i >= 0; i--) 
        adjust(i, n);
    // 先将第一个元素和已经排好的元素前一位做交换，再重新调整（刚调整的元素之前的元素），直到排序完毕
    for (int i = n - 1; i > 0; i--) {
        swap(&a[0], &a[i]);
        adjust(0, i);
    }

    for(int i = 0; i < n ;i++)
        printf("%d ", a[i]);

    return 0;
}