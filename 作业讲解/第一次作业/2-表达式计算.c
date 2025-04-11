#include <stdio.h>

int num[1005];
char op[10005];

int read() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

int main() {
    int cnt = 1;
    num[1] = read();

    char ch;
    while (scanf(" %c", &ch)) {
        if(ch == '+' || ch == '-')  
            op[cnt] = ch, num[++cnt] = read();
        else if(ch == '*')
            num[cnt] *= read();
        else if(ch == '/')
            num[cnt] /= read();
        else break;
    }

    int ans = num[1];
    for(int i = 1; i < cnt; i++) 
        if(op[i] == '+')
            ans += num[i + 1];
        else 
            ans -= num[i + 1];
        
    printf("%d", ans);

    return 0;
}