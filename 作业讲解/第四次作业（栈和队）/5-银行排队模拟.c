#include <stdio.h>

int readInt() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

typedef struct node node;

int a[1005], ans[1005], vis[1005];
struct node {
    int arrival, service, id;
};

int front = 0, rear = -1;
node que[10005];

void push(int coming, int serve, int id) {
    rear++;
    que[rear].arrival = coming;
    que[rear].service = serve;
    que[rear].id = id;
}

void lazySkip() {
    while(front <= rear && que[front].service == 0)
        front++;
}

int wait = 0;
// 在 t 时刻为队列的前 k 个人提供服务
void serve(int t, int k) {
    int tem = front, cnt = 0;
    while(tem <= rear && cnt < k) {
        if(que[tem].service == 0) {
            tem++;
            continue;
        }
        if(!vis[que[tem].id]) 
            vis[que[tem].id] = 1, wait--, ans[que[tem].id] = t - que[tem].arrival;
        que[tem].service--;
        cnt++, tem++;
    }
}

int queNum = 3, n;
void atTime(int t) {
    if(t <= n)
        while(wait >= queNum * 7 && queNum < 5)
            queNum++;
    lazySkip();
    serve(t, queNum);
    while(wait < queNum * 7 && queNum > 3)
        queNum--;
}

int main() {
    n = readInt();
    int time = 0, id = 0, total = 0;
    for(int i = 1; i <= n; i++)
        a[i] = readInt(), total += a[i];
    for(int i = 1; i <= n; i++) {
        time++;
        wait += a[i];
        // 排队
        for(int j = 0; j < a[i]; j++) 
            push(time, readInt(), ++id);
        atTime(time);
    }

    while(front <= rear) 
        atTime(++time);

    for(int i = 1; i <= total; i++)
        printf("%d : %d\n", i, ans[i]);
    return 0;
}