#include <stdio.h>
#include <string.h>

int read() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

char str[10005]; // 原字符串
char str3[10005];// 处理后的 : 后的字符串
char str2[10005];// 处理后的 : 前的字符串
char geshi[10005];

int main() {
    
    int n = read();
    sprintf(geshi, "%-%%ds", n - 2);
    // 吃掉第一行有效语句前的所有无效字符
    while(getchar() != '\n');
    
    while(gets(str)) {
        memset(str2,0,sizeof(str2));
        memset(str3,0,sizeof(str3));
        int len = strlen(str);
        int pos = 0;
        int pos2 = 0, pos3 = 0; // 记录 str2 和 str3 枚举到的位置
        
        for(pos = 0;str[pos] != ':'; pos++) {
            // 合并空格和制表符为空格
            if(str[pos] == ' ' || str[pos] == '\t') {
                if(str2[pos2 - 1] != ' ')
                    str2[pos2++] = ' ';
            }
            else 
                str2[pos2++] = str[pos];
        }
        if(str2[pos2 - 1] == ' ')
            str2[pos2 - 1] = 0;
        
        str3[pos3++] = ' ';

        pos++;  // 跳过 :
        for(;str[pos];pos++) {
            // 合并空格和制表符为空格
            if(str[pos] == ' ' || str[pos] == '\t') {
                if(str3[pos3 - 1] != ' ')
                    str3[pos3++] = ' ';
            }
            else 
                str3[pos3++] = str[pos];
        }

        printf(geshi, str2);
        printf(" :%s\n", str3);
    }

    return 0;
}