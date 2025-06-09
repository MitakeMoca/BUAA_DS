#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int readInt() {
    int tem;
    scanf("%d", &tem);
    return tem;
}

typedef struct node  node;
typedef struct node* nptr;

// 记录边的线路和临接点
struct node {
    int line, to;
    nptr nxt;
};

nptr newnode() {
    return (nptr)malloc(sizeof(node));
}

nptr getnode(int line, int to) {
    nptr p = newnode();
    p -> line = line;
    p -> to = to;
    p -> nxt = NULL;
    return p;
}

// 原文件只有 410 行
nptr e[505];

void add_edge(int from, int line, int to) {
    nptr p = getnode(line, to);
    p -> nxt = e[from];
    e[from] = p;
}

char begin[55], end[55], tem[55];
char *station[505];
int total;  // 记录车站的总数

int find(char *s) {
    // 如果一个车站名之前有出现过，那么返回它的编号
    for(int i = 0; i < total; i++) 
        if(strcmp(station[i], s) == 0) 
            return i;
    // 否则，将它插在 station 数组的末尾，并返回它的编号
    station[total] = (char *)malloc(strlen(s) + 1);
    strcpy(station[total], s);
    return total++;
}

// 分别记录每个点被谁更新，起点到每个点当前的最短距离，每个点是否已经被访问过，以及每个点被其它结点松弛时走的线路
int from[505], dis[505], vis[505], from_line[505];
void Dijkstra(int s) {
    memset(from, -1, sizeof(from));
    // 相当于把 dis 数组初始化为 0x3f3f3f3f，也就是无穷大
    memset(dis, 0x3f, sizeof(dis)); 
    // 起点到起点的距离为 0
    dis[s] = 0; 
    for(int i = 0; i < total; i++) {
        // 找到未被访问过的距离起点最近的点
        int u = -1, min_dis = 0x3f3f3f3f; 
        for(int j = 0; j < total; j++) 
            if(!vis[j] && dis[j] < min_dis) 
                u = j, min_dis = dis[j];
        
        // 标记为已访问
        vis[u] = 1; 
        for(nptr p = e[u]; p; p = p -> nxt) {
            int v = p -> to;
            // 松弛操作，所有边的长度都是 1
            if(!vis[v] && dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                from[v] = u;
                from_line[v] = p -> line;
            }
        }
    }
}

// 分别记录路径上坐了几号地铁，每次坐地铁坐了多少站，起点 + 换乘站 + 终点的编号，以及换乘了几次
// 换乘了几次就相当于路径的长度，最后输出的车站数 = 路径长度 + 1
int path[505], length[505], sta[505], cnt;
void print_path(int s, int t) {
    int line = -1;
    while(t != s) {
        if(from_line[t] != line) {
            line = from_line[t];
            path[++cnt] = line;
            sta[cnt] = t;
        }
        length[cnt]++;
        t = from[t];
    }
    printf("%s", station[s]);
    for(int i = cnt; i > 0; i--) {
        printf("-%d(%d)-", path[i], length[i]);
        printf("%s", station[sta[i]]);  
    }
}

int main() {
    scanf("%s%s", begin, end);
    freopen("bgstations.txt", "rb", stdin);
    int line_num = readInt();
    // 建图
    for(int i = 0; i < line_num; i++) {
        int line = readInt(), station_num = readInt();
        int pre = -1, now = 0;
        for(int j = 0; j < station_num; j++) {
            scanf("%s", tem);
            int is_change = readInt();
            now = find(tem);
            // 如果不是始发站，那么就将它和前一个车站连起来
            if(pre != -1) {
                add_edge(pre, line, now);
                add_edge(now, line, pre);
            }
            pre = now;
        }
    }

    int s = find(begin), t = find(end);
    Dijkstra(s);
    // 根据 Dijkstra 维护的信息输出题目指定的格式
    print_path(s, t);
    return 0;
}