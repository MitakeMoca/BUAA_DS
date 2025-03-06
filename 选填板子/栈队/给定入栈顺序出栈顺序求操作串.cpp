/*
    用 S 表示入栈操作，X 表示出栈操作，给定元素的入栈顺序和出栈顺序，求相应的 S 和 X 的操作串
    输入：第一行一个整数 n 表示元素个数，第二行元素入栈顺序，第三行元素出栈顺序
    输出：一行只含有 S 和 X 的字符串，表示操作序列

    示例输入：
        4
        ABCD
        ACDB
    
    示例输出：
        SXSSXSXX
*/

#include <stdio.h>
#include <string.h>

int read() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

char input[105], output[105];
char stack[105];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int main() {
    int n = read();
    getchar();
    gets(input);
    gets(output);

    int j = 0;   // output 下标
    for(int i = 0; i < n ;i++) {
        push(input[i]);
        putchar('S');
        while(top != -1 && stack[top] == output[j]) 
            putchar('X'), pop(), j++;
    }
    return 0;
}