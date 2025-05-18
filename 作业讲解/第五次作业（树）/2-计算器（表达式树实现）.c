#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int readInt() {
    int tem;
    scanf("%d", &tem);
    return tem;
}

typedef struct node  node;
typedef struct node* nptr;
struct node {
    int type;
    int num;
    char op;
    nptr ls, rs;
};

nptr newnode() {
    return (nptr)malloc(sizeof(node));
}

nptr getnode(int type, int num, char op) {
    nptr p = newnode();
    p -> type = type;
    p -> num = num;
    p -> op = op;
    p -> ls = NULL;
    p -> rs = NULL;
    return p;
}

char str[1005];

nptr stack[105], post[105];
int top = -1, cnt = 0;

void push(nptr p) {
    stack[++top] = p;
}

nptr pop() {
    return stack[top--];
}

int pre(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 0;
        default:
            return -1;
    }
}

void build_post() {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(isdigit(str[i])) {
            int num = 0;
            while(isdigit(str[i])) {
                num = num * 10 + str[i] - '0';
                i++;
            }
            nptr p = getnode(0, num, 0);
            post[cnt++] = p;
            // 此时 str[i] 一定不是数字，由此保证有没有进入到这个分支，交给下面分支的都是一个字符
        }
        if(str[i] == ' ')
            continue;
        if(str[i] == '=')
            break;
        if (str[i] == '(') {
            push(getnode(1, 0, str[i]));
        } else if (str[i] == ')') {
            while (top != -1 && stack[top] -> op != '(') {
                post[cnt++] = pop();
            }
            pop();
        } else {  // 处理操作符
            while (top != -1 && pre(stack[top] -> op) >= pre(str[i])) 
                post[cnt++] = pop();
            push(getnode(1, 0, str[i]));
        }
    }

    while(top != -1) {
        post[cnt++] = pop();
    }
}

void build_tree() {
    for(int i = 0; i < cnt; i++) {
        // 是数字，直接建立单节点树并入栈，单节点树就相当于带 ls、rs 字段的结点
        if(post[i] -> type == 0) {
            stack[++top] = post[i];
        } else {
            post[i] -> rs = pop();
            post[i] -> ls = pop();
            stack[++top] = post[i];
        }
    }
}

void printNode(nptr p) {
    if(p == NULL)
        return ;
    if(p -> type == 0)
        printf("%d ", p -> num);
    else 
        printf("%c ", p -> op);
}

int cal(char op, int a, int b) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
    }
}

void postDfs(nptr p) {
    // 递归边界一定是叶子结点，不用考虑空节点了
    // 因为非叶子结点一定有两个儿子，因为这些操作符必须都要有两个操作数
    if(p -> type == 0)
        return ;
    postDfs(p -> ls);
    postDfs(p -> rs);
    p -> num = cal(p -> op, p -> ls -> num, p -> rs -> num);
}

int main() {
    gets(str);
    // 建立后缀表达式
    build_post();
    // 建立表达式树
    build_tree();
    nptr root = stack[0];
    printNode(root);
    printNode(root -> ls);
    printNode(root -> rs);
    printf("\n");
    postDfs(root);
    printf("%d\n", root -> num);
    return 0;
}