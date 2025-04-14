#include <stdio.h>
#include <ctype.h>

double numStk[205];
char opStk[205];
int numTop, opTop;

// 如果 op1 的优先级高于或等于 op2 返回 1 否则返回 0
int cmp(char op1, char op2) {
    if(op1 == '(') 
        return 0;
    return (op1 == '*' || op1 == '/') || (op2 == '+' || op2 == '-');
}

void cal(char c) {
    double a = numStk[--numTop];
    double b = numStk[--numTop];
    if(c == '+') numStk[numTop++] = b + a;
    else if(c == '-')   numStk[numTop++] = b - a;
    else if(c == '*')   numStk[numTop++] = b * a;
    else numStk[numTop++] = b / a;
}

char str[1005];

int main() {
    int ret = 0;
    int num;
    char op;
    gets(str);
    int i = 0;
    while (str[i]) {
        char op = str[i];
        i++;
        if (op == ' ')
            continue;
        if (!isdigit(op)) { // 说明是一个符号
            if (op == '=') break;
            if (opTop == 0 || opStk[opTop - 1] == '(') {
                opStk[opTop++] = op;
            } else if (op == '(') {
                opStk[opTop++] = op;
            } else if (op == ')') {
                while (opTop > 0 && opStk[opTop - 1] != '(') 
                    cal(opStk[--opTop]);
                opTop--; // 弹出'('
            } else {
                while (opTop > 0 && cmp(opStk[opTop - 1], op)) 
                    cal(opStk[--opTop]);
                opStk[opTop++] = op;
            }
        } else { // 读取数字
            double num = op - '0';
            while (isdigit(str[i])) {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            numStk[numTop++] = num;
        }
    }

    while (opTop > 0) 
        cal(opStk[--opTop]);

    printf("%.2lf", numStk[0]);

    return 0;
}