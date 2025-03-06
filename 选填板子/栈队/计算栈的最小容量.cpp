/*
    设栈 S 和队列 Q 的初始状态为空，n 个元素依次通过栈 S，一个元素出栈后即进队列 Q
    若 6 个元素出队的序列给定，则栈 S 的容量至少应该是
    输入：第一行一个整数 n 表示元素个数，第二行元素入栈顺序，第三行元素出队顺序
    输出：栈的最小容量

    示例输入：
        6
        a b c d e f
        b d c f e a
    
    示例输出：
        3

    拓展：
        这道题同样也是以下题目的模板：
            设有一顺序栈 S ，n 个元素依次进栈，如果元素出栈的顺序给定，则栈的容量至少应该是
            即没有队也是这个板子
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
int ans = 0;

// 入栈
void push(char ele) {
    stack[++top] = ele;
    if(top >= ans)
        ans = top + 1;
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

    printf("%d\n", ans);
    
    return 0;
}