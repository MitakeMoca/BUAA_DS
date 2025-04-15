#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 分别表示网站和网页
char website[105][85], vis[105], totalWeb;
char page[105][85], totalPage;
// 后退栈和前进栈
int backStk[105], backTop = -1;
int forwardStk[105], forwardTop = -1;
char op[15], url[85];

int readInt() {
    int tem;
    scanf("%d", &tem);
    return tem;
}

int findPage(char *url) {
    for(int i = 0; i < totalPage; i++) {
        if(strcmp(page[i], url) == 0) 
            return i;
    }
    strcpy(page[totalPage], url);
    return totalPage++;
}

void updateWebsite(int i) {
    char *tem = (char *)malloc(85);
    strcpy(tem, page[i] + strlen("https://"));
    char *p = tem;
    while(*p != '/') p++;
    *p = 0; // 截断字符串
    for(int i = 0; i < totalWeb; i++) 
        if(strcmp(website[i], tem) == 0) {
            vis[i]++;
            return ;
        }
    strcpy(website[totalWeb], tem);
    vis[totalWeb++] = 1;
}

// 浏览过的网页
int history[105], total;

int main() {
    // 特殊处理初始页面
    int current = findPage("https://www.baidu.com/");
    history[total++] = current;
    updateWebsite(current);
    while(1) {
        scanf("%s", op);
        if(strcmp(op, "VISIT") == 0) {
            backStk[++backTop] = current;
            scanf("%s", url);
            forwardTop = -1; // 清空前进栈
            current = findPage(url);
        } else if(strcmp(op, "<<") == 0) {
            if(backTop == -1)
                continue;
            forwardStk[++forwardTop] = current;
            current = backStk[backTop--];
        } else if(strcmp(op, ">>") == 0) {
            if(forwardTop == -1)
                continue;
            backStk[++backTop] = current;
            current = forwardStk[forwardTop--];
        } else
            break;
        
        // 记录访问过的网页
        history[total++] = current;
        updateWebsite(current);
    }

    int tem = readInt();
    for(int i = 0; i < total; i++)
        printf("%s\n", page[history[i]]);
    
    if(tem == 0) {
        // 还要找到浏览次数最多的网站
        int maxVis = 0, maxId = -1;
        for(int i = 0; i < totalWeb; i++) {
            if(vis[i] > maxVis) {
                maxVis = vis[i];
                maxId = i;
            }
        }
        printf("%s %d", website[maxId], maxVis);
    }
}