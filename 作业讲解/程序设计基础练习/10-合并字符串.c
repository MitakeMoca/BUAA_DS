#include <stdio.h>
#include <string.h>

char a[10005], b[10005], ans[10005];

int main() {
    // 从 1 开始读入
    scanf("%s", a + 1);
    scanf("%s", b + 1);

    int n = strlen(a + 1), m = strlen(b + 1);
    int i = 1, j = 1;
    int cnt = 0;
    
    while(i <= n && j <= m) {
        if(a[i] < b[j])
            ans[++cnt] = a[i], i++;
        else
            ans[++cnt] = b[j], j++;
    }
    while(i <= n)
        ans[++cnt] = a[i], i++;
    while(j <= m)
        ans[++cnt] = b[j], j++;

    printf("%s", ans + 1);
    return 0;
}