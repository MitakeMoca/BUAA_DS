#include <stdio.h>

char str[100005];
int dp[100005]; // 表示以某位置结尾的最长升序子串长度

int myMax(int a,int b) {
    return a > b ? a : b;
}

int main() {
    scanf("%s", str + 1);
    int len = strlen(str + 1);
    int ans = 0;
    for(int i = 1;i <= len;i++) {
        dp[i] = 1;
        for(int j = 1;j < i;j++)
            if(str[j] <= str[i])
                dp[i] = myMax(dp[i], dp[j] + 1);
        ans = myMax(ans,dp[i]);
    }
    printf("%d",ans);

    return 0;
}
