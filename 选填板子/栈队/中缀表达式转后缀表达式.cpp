/*
    中缀表达式转后缀表达式
    输入：一行字符串，表示中缀表达式，每个操作数都是字母变量，中间可以有多余的空格
    输出：一行字符串，表示中缀表达式对应的后缀表达式

    示例输入：A-(B+C/D)*E
    示例输出：ABCD/+E*-
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char stack[105];
int top = -1;

void push(char value) {
    stack[++top] = value;
}

char pop() {
    return stack[top--];
}

int isOp(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')';
}

// 运算符优先级
int pre(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 0;
        default:
            return -1;
    }
}

char a[105], b[105];

int main() {
    gets(a);
    puts(a);
    int k = 0;
    int len = strlen(a);
    
    for (int i = 0; i < len; i++) {
        char ch = a[i];

        if (ch == ' ') 
            continue;

        if (isalpha(ch)) {
            b[k++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                b[k++] = pop();
            }
            pop();
        } else if (isOp(ch)) {  // 处理操作符
            while (top != -1 && pre(stack[top]) >= pre(ch)) 
                b[k++] = pop();
            
            push(ch);
        }
    }

    // 弹出剩余的操作符
    while (top != -1) 
        b[k++] = pop();

    puts(b);
    return 0;
}
