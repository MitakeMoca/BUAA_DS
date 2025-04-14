#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int read( ) {
    int tem;
    scanf("%d",&tem);
    return tem;
}

typedef struct bracket  bracket;
struct bracket {
    char bracket;
    int line;
};

bracket stk[205];
char bracketStk[205];
int top, bracketTop;

void bracketError(bracket b) {
    printf("without maching \'%c\' at line %d", b.bracket, b.line);
    exit(0);
}

int main() {
    freopen("example.c", "rb", stdin);
    char ch;
    int skip = 0, line = 1;   // 1 代表单行注释 2 代表多行注释 3 代表字符串常量 4 代表多行注释且上一个字符是 * 5 代表上一个字符是 / 6 代表字符常量
    while(~scanf("%c", &ch)) {
        if(ch == '\n')
            line++;
        if(skip == 1) {
            if(ch == '\n')  skip = 0;
            continue;
        } else if(skip == 2) {
            if(ch == '*')   skip = 4;
        } else if(skip == 3) {
            if(ch == '\"')    skip = 0;
            continue;
        } else if(skip == 4) {
            if(ch == '/')  skip = 0;
            else if(ch != '*') skip = 2;
            continue;
        } else if(skip == 5) {
            if(ch == '/') skip = 1;
            else if(ch == '*')  skip = 2;
            else skip = 0;
        } else if(skip == 6) {
            if(ch == '\'')  skip = 0;
            continue;
        } 
        if(skip == 0) {
            if(ch == '/')  skip = 5;
            else if(ch == '\"')   skip = 3;
            else if(ch == '\'')   skip = 6;
            else if(ch == '{') {
                if(stk[top].bracket == '(') bracketError(stk[top]);
                else {
                    stk[++top].bracket = '{';
                    stk[top].line = line;
                }
                bracketStk[++bracketTop] = '{';
            } else if(ch == ')') {
                bracket tem = {')', line};
                if(stk[top].bracket != '(') bracketError(tem);
                else top--;
                bracketStk[++bracketTop] = ')';
            } else if(ch == '}') {
                bracket tem = {'}', line};
                if(stk[top].bracket != '{') bracketError(tem);
                else top--;
                bracketStk[++bracketTop] = '}';
            } else if(ch == '(') {
                stk[++top].bracket = '(';
                stk[top].line = line;
                bracketStk[++bracketTop] = '(';
            }
        }
    }

    if(top != 0)    
        bracketError(stk[top]);

    for(int i = 1;i <= bracketTop;i++)
        printf("%c", bracketStk[i]);
    return 0;
}
