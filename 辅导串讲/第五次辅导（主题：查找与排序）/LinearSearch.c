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
    for(int i = 1; i <= n ;i++) 
        a[i] = read();

    int target = read();

    for(int i = 1; i <= n ;i++) {
        if(a[i] == target) {
            printf("%d", i);
            return 0;
        }
    }

    printf("-1");
    return 0;
}