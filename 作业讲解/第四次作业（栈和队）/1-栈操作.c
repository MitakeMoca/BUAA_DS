#include <stdio.h>
#include <string.h>

int readInt() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

int stk[1005], top;

int main() {
    int op;
    while((op = readInt()) != -1) {
        if(op == 1) {
            if(top > 100)  printf("error ");
            else stk[++top] = readInt();
        }
        else {
            if(top <= 0)    printf("error ");
            else printf("%d ", stk[top--]);
        }
    }

    return 0;
}