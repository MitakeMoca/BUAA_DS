#include <stdio.h>

int num[1005];
char op[10005];

int readInt() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

int main() {
    int cnt = 1;
    num[1] = readInt();

    char ch;
    while (scanf(" %c", &ch)) {
        if(ch == '+' || ch == '-')  
            op[cnt] = ch, num[++cnt] = readInt();
        else if(ch == '*')
            num[cnt] *= readInt();
        else if(ch == '/')
            num[cnt] /= readInt();
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