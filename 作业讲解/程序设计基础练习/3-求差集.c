#include <stdio.h>

int a[1000005];

int read() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

int main() {
    int tem;
    int cnt = 0;
    while((tem = read()) != -1)
        a[++cnt] = tem;
    while((tem = read()) != -1) {
        for(int i = 1; i <= cnt; i++) 
            if(a[i] == tem) {
                a[i] = -1;
            }
    }
    for(int i = 1;i <= cnt;i++)
        if(a[i] != -1)    
            printf("%d ",a[i]);

    return 0;
}
