#include <stdio.h>
#include <string.h>

int num1[105], num2[105];
char tem[105], ans[105];

int read() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

int max(int a, int b) {return a > b ? a : b;}
int cmp(int *a, int *b, int n) {
    for(int i = n;i >= 0;i--)
        if(a[i] < b[i]) return -1;
        else if(a[i] > b[i])    return 1;
    return 0;
}

int main() {

    gets(tem);
    int len1 = strlen(tem);
    for(int i = 0; i < len1; i++)
        num1[len1 - i - 1] = tem[i] - '0';
    
    gets(tem);
    int len2 = strlen(tem);
    for(int i = 0; i < len2; i++)
        num2[len2 - i - 1] = tem[i] - '0';

    int maxLen = max(len1, len2);

    int comp = cmp(num1, num2, maxLen);
    if(comp == 0)  return printf("0"), 0;

    for(int i = 0; i < maxLen; i++) 
        num1[i] = (num1[i] - num2[i]) * comp;

    for(int i = 0; i < maxLen - 1; i++) 
        if(num1[i] < 0)  num1[i] += 10, num1[i + 1] -= 1;
    
    int cnt = maxLen;
    while(num1[cnt] == 0 && cnt > 0)
        cnt--;
    
    if(comp == -1)  printf("-");

    for(int i = cnt; i >= 0; i--)
        printf("%d", num1[i]);
    return 0;
}