#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int readInt() {
    int tem;
    scanf("%d", &tem);
    return tem;
}

typedef struct operate operate;
struct operate {
    int op, pos;
    char *str;
};

operate opStk[205];
int opTop = 0;

char str[1005], tem[1005];

void push(int op, int pos) {
    opStk[opTop].op = op;
    opStk[opTop].pos = pos;
    char *p = (char *)malloc(strlen(tem) + 1);
    strcpy(p, tem);
    opStk[opTop].str = p;
    opTop++;
}

// 在指定位置插入一个字符串
void insert(int pos) {
    int len = strlen(tem);
    // 必须引入一个中间字符串
    char *p = (char *)malloc(strlen(str) + 1);
    strcpy(p, str + pos);
    strcpy(str + pos + len, p);
    strncpy(str + pos, tem, len);
}

// 删除指定位置 len 个字符
void del(int pos, int len) {
    int total = strlen(str);
    if(pos + len > total) 
        len = total - pos;
    // 先维护 tem
    strncpy(tem, str + pos, len);
    tem[len] = 0;
    // 必须引入一个中间字符串
    char *p = (char *)malloc(strlen(str) + 1);
    strcpy(p, str + pos + len);
    strcpy(str + pos, p);
}

// 撤销一次操作
void undo() {
    if(opTop == 0) 
        return;
    operate op = opStk[--opTop];
    if(op.op == 1) 
        del(op.pos, strlen(op.str));
    else if(op.op == 2) {
        // 要先维护 tem
        strcpy(tem, op.str);
        insert(op.pos);
    }
}

int main() {
    gets(str);

    // 先读入已经做完的操作
    int n = readInt();
    for(int i = 1; i <= n; i++) {
        int op = readInt(), pos = readInt();
        scanf("%s", tem);
        push(op, pos);   
    }

    // 读入新的操作
    while(1) {
        int op = readInt();
        if(op == -1)
            break;
        if(op == 1) {
            // 插入操作
            int pos = readInt();
            scanf("%s", tem);
            insert(pos);
            push(op, pos);
        } else if(op == 2) {
            // 删除操作，在 del 里还要维护 tem
            int pos = readInt(), len = readInt();
            del(pos, len);
            push(op, pos);
        } else
            undo();
    }
    printf("%s", str);

    return 0;
}