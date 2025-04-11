// que 代表队数组，front 代表队首，rear 代表队尾
int que[1005];
int front = 0, rear = -1;

void enqueue(int a) {
    que[++rear] = a;
}

int dequeue() {
    return que[front++];
}

int getLen() {
    return rear - front + 1;
}
