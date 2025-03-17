#include <stdio.h>

// 复杂度 O sqrt(n)
int read() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

int main() {
    int n = read();
    int i = 2;
    while(i * i <= n) {
        while(n % i == 0)
            printf("%d ", i), n /= i;
        i++;
    }
    if(n != 1)   printf("%d", n);

    return 0;
}
