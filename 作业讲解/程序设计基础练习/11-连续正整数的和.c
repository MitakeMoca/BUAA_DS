#include <stdio.h>

// 贪心：数字越小越多，从小到大枚举

int readInt() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

int main() {
    int n = readInt();
    for(int i = 1; i < n; i++) { // 从 1 开始枚举
        int sum = i, cnt = i + 1;
        while(sum < n) 
            sum += cnt, cnt++;
        // 说明这个是项数最多的解
        if(sum == n) {
            printf("%d=%d", n, i);
            int sum2 = i,cnt = i + 1;
            while(sum2 < n) 
                printf("+%d",cnt), sum2 += cnt, cnt++;
            return 0;
        } 
    }
    printf("No Answer\n");
    return 0;
}
