// ���ַ�������
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int readInt() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

char str[1005];
char identArr[1005][105];

int cmp(const void *a, const void *b) {
    char *x = (char *)a;
    char *y = (char *)b;
    return strcmp(x, y);
}

int main() {
    gets(str);
    int len = strlen(str);
    int m = 0, cnt = 0;  
    char ident[105];
    for(int i = 0; i < len; i++) {
        if(m == 0 && (str[i] == '_' || isalpha(str[i])))
            ident[0] = str[i], m = 1;
        else if (m != 0 && (str[i] == '_' || isalpha(str[i]) || isalnum(str[i])))
            ident[m] = str[i], m++;
        else if(m != 0) {
            ident[m] = 0;
            int flag = 0;  
            for(int i = 0;i < cnt;i++) 
                if(strcmp(identArr[i], ident) == 0) {
                    flag = 1;
                    break;
                }

            if(flag == 0)
                strcpy(identArr[cnt], ident), cnt++;
            m = 0;
        }
    }

    qsort(identArr, cnt, sizeof(identArr[0]), cmp);

    for(int i = 0; i < cnt; i++)
        printf("%s\n", identArr[i]);
    return 0;
}