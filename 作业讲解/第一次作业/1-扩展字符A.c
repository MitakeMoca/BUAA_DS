#include <stdio.h>
#include <string.h>
#include <ctype.h>

char str[10005];
char ans[10005];

int main() {
    scanf("%s", str + 1);
    int cnt = 0;
    int len = strlen(str + 1);
    for(int i = 1; i <= len;i++) {
        if(str[i] == '-') {
            if((islower(str[i - 1]) && islower(str[i + 1])
                || isupper(str[i - 1]) && isupper(str[i + 1]) 
                || isdigit(str[i - 1]) && isdigit(str[i + 1]))
                && str[i - 1] < str[i + 1]
            )
                for(char j = str[i - 1] + 1;j < str[i + 1];j++)
                    ans[++cnt] = j;
            else ans[++cnt] = '-';
        } else ans[++cnt] = str[i];
    }
        
    printf("%s", ans + 1);

    return 0;
}