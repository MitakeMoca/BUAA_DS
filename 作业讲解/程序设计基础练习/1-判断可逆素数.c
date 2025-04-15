#include <stdio.h>
typedef long long ll;
const int maxn = 1e5 + 5;

int readInt() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

int isPrime(int i) {
    for(int j = 2; j * j <= i; j++)
        if(i % j == 0)  return 0;
    return 1;
}

int reserve(int num) {
    int ret = 0;
    while(num) {
        ret = ret * 10 + num % 10;
        num /= 10;
    }
    return ret;
}

int main() {
    int num = readInt();
    if(isPrime(num) && isPrime(reserve(num)))
        printf("yes");
    else
        printf("no");
    return 0;
}


