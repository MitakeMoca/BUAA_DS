#include <stdio.h>

int main() {
    freopen("fcopy.in", "rb", stdin);
    freopen("fcopy.out", "wb", stdout);

    char ch;
    // 用 sta 表示状态
    int sta = 1;    
    while((ch = getchar()) != EOF) {
        // 如果是空白字符
        if(ch == ' ' || ch == '\n' || ch == '\r') {
            // 如果在状态 1，就切换状态
            if(sta == 1)
                sta = 2;
        }
        else if(sta == 1) // 非空白符且在状态 1
            printf("%c", ch);
        else if(sta == 2) // 非空白符且在状态 2
            printf(" %c", ch), sta = 1;
    }

    // 保险起见最后再检查一下如果最后以几个空白符结尾的情况
    // 虽然一般的 OJ 上对最后是否有空白符并不做严格检查
    if(sta == 2)
        printf(" ");
    return 0;
}