#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// easy hash
int ha[27];
char str[1000005];

int myMax(int a, int b) {
    return a > b ? a : b;
}

int main() {

    // 统计出现次数
    while(scanf("%s",str) !=EOF) {
        int len = strlen(str);
        for(int i = 0;i < len;i++)
            if(str[i] >= 'a' && str[i] <= 'z')
                ha[str[i] - 'a']++;
    }

    // 统计所有字母的最大出现次数
    int cnt = 0;
    for(int i = 0;i < 26;i++)   
        cnt = myMax(cnt, ha[i]);
    
    // 依次处理每一行
    while(cnt != 0) {
        for(int i = 0;i < 26;i++) {
            if(ha[i] >= cnt)    
                printf("*");
            else 
                printf(" ");
        }  
        cnt--;
        printf("\n");
    }

    // 最后输出一行字母
    for(int i = 0; i < 26; i++)
        printf("%c", 'a' + i);
    return 0;
}
