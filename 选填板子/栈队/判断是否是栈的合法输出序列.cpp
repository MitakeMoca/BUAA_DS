/*
    给定一个栈的输入序列，判断某个输出序列是不是栈的合法输出序列
    输入：第一行一个整数 n 表示元素个数，第二行元素入栈顺序，第三行元素出栈顺序
    输出：0 或者 1，1 代表是合法输出序列，0 代表不是合法输出序列

    示例输入 1：
        5
        a b c d e
        c b a e d
    示例输出 1：
        1

    示例输入 2：
        5
        a b c d e
        d c a b e
    示例输出 2：
        0
*/

#include <stdio.h>
#include <string.h>

int read() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

char element[105];
char stack[105], queue[105];
int top = -1, front, rear;  // 分别代表栈顶，队头和队尾

// 入栈
void push(char ele) {
    stack[++top] = ele;
}

// 元素出栈
int pop() {
    return stack[top--];
}

int main() {
    int n = read();
    for(int i = 0; i < n ;i++)
        scanf(" %c", &element[i]);
    for(int i = 0; i < n ;i++)
        scanf(" %c", &queue[i]); // 表示入队顺序
    front = 0, rear = n - 1;

    for(int i = 0; i < n ;i++) {
        push(element[i]);
        // 栈不为空 且 栈顶 = 队头 
        while(top > -1 && stack[top] == queue[front])
            pop(), front++;
    }

    // 队和栈都为空
    printf("%d\n", top == -1 && rear < front);
    
    return 0;
}