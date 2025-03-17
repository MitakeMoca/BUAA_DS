#include <stdio.h>

int main() {
    int total = 0, zhushi = 0;
    int sta = 0;
    char ch;    // 用来读入新的字符
    while(scanf("%c", &ch) != EOF) {
        total++;

        // 因为 * 可能是多行注释结束的标志，不作为多行注释的一部分
        if(sta == 2 && ch != '*')
            zhushi++;
        
        if(sta == 0 && ch == '/')   sta = 1;
        else if(sta == 1 && ch == '*')  sta = 2; 
        else if(sta == 2 && ch == '*')  sta = 3;
        else if(sta == 3 && ch == '/')  sta = 0;
        else if(sta == 3 && ch == '*')  zhushi++;   // 证明我们上一个 * 时注释的一部分
        else if(sta == 3)   sta = 2;    // 虚惊一场，仍在注释中
    }

    printf("%d%%", zhushi * 100 / total);

    return 0;
}