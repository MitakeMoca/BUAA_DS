#include <stdio.h>
#include <string.h>

char str[10005];
char subStr[10005];
char ans[10005];

int main() {
    scanf("%s", str);
    scanf("%s", subStr);
    int pos = 0;
    int find = 0;
    int cnt = 0, len = strlen(subStr), len2 = strlen(str);

    while ((find = strstr(str + pos, subStr) - str) > -1) {
        for(int i = pos; i < find; i++)
            ans[++cnt] = str[i];
        pos = find + len;
    }
    
    for(int i = pos; i < len2; i++)
        ans[++cnt] = str[i];
    
    printf("%s", ans + 1);

    return 0;
}   