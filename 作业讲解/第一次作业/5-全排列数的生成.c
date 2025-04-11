#include <stdio.h>

int now[15], vis[15], n;

int read() {
    int tem;
    scanf("%d", &tem);
    return tem;
}

void printAns() {
    for(int i = 1; i <= n; i++)
        printf("%d ", now[i]);
    printf("\n");
    return ;
}

void dfs(int i) {
    if(i == n) {
        printAns();
        return;
    }

    for(int j = 1; j <= n; j++) 
        if(!vis[j]) now[i + 1] = j, vis[j] = 1, dfs(i + 1), vis[j] = 0;
    
    return;
}

int main() {
    n = read();
    dfs(0);
    return 0;
}