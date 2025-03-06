/*
    后缀表达式转中缀表达式
    输入：一行字符串，表示后缀表达式，每个操作数都是字母变量，中间可以有多余的空格
    输出：一行字符串，表示后缀表达式对应的中缀表达式

    示例输入：ABCD/+E*-
    示例输出：(A-((B+(C/D))*E))
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char stack[105][105];
int top = -1;

void push(char* str) {
    strcpy(stack[++top], str);
}

char* pop() {
    return stack[top--];
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int main() {
    char postfix[105];
    char infix[105 * 2]; // 预留足够的空间存储中缀表达式
    gets(postfix);
    
    int len = strlen(postfix);
    
    for (int i = 0; i < len; i++) {
        char ch = postfix[i];

        if (ch == ' ') 
            continue;

        if (isalpha(ch)) {
            char operand[2] = {ch, '\0'};
            push(operand);
        } else if (isOperator(ch)) {
            char operand2[105], operand1[105];
            strcpy(operand2, pop());
            strcpy(operand1, pop());

            snprintf(infix, sizeof(infix), "(%s%c%s)", operand1, ch, operand2);
            push(infix);
        }
    }
    
    printf("%s\n", stack[top]);
    return 0;
}
