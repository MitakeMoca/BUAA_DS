// top 维护栈顶，栈底一直是 0
int stk[1005], top = -1;

void push(int a) {
    stk[++top] = a;
}

int pop() {
    return stk[top--];
}

int peek() {
    return top == -1 ? -1 : stk[top];
}