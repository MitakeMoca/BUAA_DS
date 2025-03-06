/*
    中缀表达式转前缀表达式
    输入：一行字符串，表示中缀表达式，每个操作数都是字母变量，中间可以有多余的空格
    输出：一行字符串，表示中缀表达式对应的前缀表达式

    示例输入：A-(B+C/D)*E
    示例输出：-A*+B/CDE
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

void reverseString(char* str, int len) {
    int start = 0;
    int end = len - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void replaceParentheses(char* str, int len) {
    for (int i = 0; i < len; i++) {
        if (str[i] == '(') {
            str[i] = ')';
        } else if (str[i] == ')') {
            str[i] = '(';
        }
    }
}

int main() {
    gets(a);
    puts(a);
    int len = strlen(a);
    
    reverseString(a, len);
    replaceParentheses(a, len);
    
    int k = 0;
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
            while (top != -1 && pre(stack[top]) > pre(ch)) 
                b[k++] = pop();
            
            push(ch);
        }
    }

    // 弹出剩余的操作符
    while (top != -1) 
        b[k++] = pop();
    
    b[k] = '\0';
    reverseString(b, k);
    
    puts(b);
    return 0;
}
