#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readInt() {
    int tem;
    scanf("%d", &tem);
    return tem;
}

// 记录函数名
char *func[1005], total;
// 每个函数调用了多少子函数，编号分别是多少
int len[1005], calls[1005][50];
// 记录函数 i 是否调用过函数 j，避免重复输出
int vis[1005][1005];
int stk[1005], top = -1;

int find(char *s) {
    for(int i = 0; i < total; i++) 
        if(strcmp(func[i], s) == 0) 
            return i;
    
    func[total] = (char *)malloc(strlen(s) + 1);
    strcpy(func[total], s);
    return total++;
}

char str[1005];
int main() {
    int op;
    while(1) {
        op = readInt();
        if(op == 8) {
            scanf("%s", str);
            int newId = find(str);
            if(top != -1) {
                int topId = find(func[stk[top]]);
                if(!vis[topId][newId]) {
                    vis[topId][newId] = 1;
                    calls[topId][len[topId]++] = newId;
                }
            }
            stk[++top] = newId;
        } else 
            top--;
        if(top == -1)
            break;
    }

    // 输出阶段
    for(int i = 0; i < total; i++) {
        if(len[i] == 0) continue;
        printf("%s:", func[i]);
        for(int j = 0; j < len[i]; j++) {
            if(j) printf(",");
            printf("%s", func[calls[i][j]]);
        }
        printf("\n");
    }

    return 0;
}