#include <stdio.h>
#include <ctype.h>
#include <string.h>

char str[55], rev[55], tem[26];
int revLen, temLen;
int vis[26];

int main() {
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(isalpha(str[i]) && !vis[str[i] - 'a']) {
            str[i] = tolower(str[i]);
            vis[str[i] - 'a'] = 1;
            rev[revLen++] = str[i];
        }
    }
    strrev(rev);

    // 检查没出现的字母并且输出第一行
    for(int i = 0; i < 26; i++) {
        printf("%c", i + 'a');
        if(!vis[i]) 
            tem[temLen++] = 'a' + i;
    }
    printf("\n");     

    strcat(rev, strrev(tem));
    printf("%s", rev);

    return 0;
}