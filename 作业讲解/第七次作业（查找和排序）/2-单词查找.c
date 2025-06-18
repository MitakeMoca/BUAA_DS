#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char dict[3505][25];

int cmp_cnt, dict_sz;
int linear_search(char *target) {
    cmp_cnt = 0;
    for(int i = 0; i < dict_sz; i++) {
        cmp_cnt++;
        // 虽然我们下面用了俩 strcmp，但是其实从题目的角度看只会让比较计数 + 1
        if(strcmp(target, dict[i]) < 0)
            return 0;
        if(strcmp(target, dict[i]) == 0)
            return 1;
    }
    // 遍历到字典最后也没找到
    return 0;
}

int binary_search(char *target, int l, int r) {
    cmp_cnt = 0;
    while(l <= r) {
        int mid = l + r >> 1;
        cmp_cnt++;
        if(strcmp(target, dict[mid]) == 0)
            return 1;
        else if(strcmp(target, dict[mid]) > 0)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return 0;
}

int idx_begin[30], idx_end[30];
int index_search(char *target) {
    int idx = target[0] - 'a';
    return binary_search(target, idx_begin[idx], idx_end[idx]);
}

#define NHASH 3001
#define MULT 37
unsigned int hash(char *str) {
    unsigned int h=0;
    char *p;
    for(p = str; *p; p++)
        h = MULT * h + *p;
    return h % NHASH;
}

typedef struct node  node;
typedef struct node* nptr;
// 不直接记录值，而是记录在原数组中的位置
struct node {
    char str[25];
    nptr nxt;
};
nptr head[NHASH];

nptr newnode() {
    return (nptr)malloc(sizeof(node));
}

nptr getnode(char *str) {
    nptr p = newnode();
    strcpy(p -> str, str);
    p -> nxt = NULL;
    return p;
}

void hash_insert(char *str) {
    int ha = hash(str);
    nptr p = getnode(str);
    if(head[ha] == NULL)
        head[ha] = p;
    else if(strcmp(str, head[ha] -> str) < 0)
        p -> nxt = head[ha], head[ha] = p;
    else {
        nptr tmp = head[ha];
        while(tmp -> nxt) {
            if(strcmp(str, tmp -> nxt -> str) < 0) {
                p -> nxt = tmp -> nxt;
                tmp -> nxt = p;
                return ;
            }
            tmp = tmp -> nxt;
        }
        tmp -> nxt = p;
    }
}

int hash_search(char *target) {
    cmp_cnt = 0;
    int ha = hash(target);
    for(nptr i = head[ha]; i; i = i -> nxt) {
        cmp_cnt++;
        if(strcmp(target, i -> str) < 0)
            return 0;
        if(strcmp(target, i -> str) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *in = fopen("dictionary3000.txt", "rb");
    // 满足初始时 end < begin，从而在搜索 x 开头的单词时不会选中任何区间
    for(int i = 0; i < 26; i++)
        idx_begin[i] = -1, idx_end[i] = -2;

    while(~fscanf(in, "%s", dict[dict_sz])) {
        // 维护某字母对应的区间
        int idx = dict[dict_sz][0] - 'a';
        if(idx_begin[idx] == -1)
            idx_begin[idx] = dict_sz;
        idx_end[idx] = dict_sz;
        hash_insert(dict[dict_sz]);
        dict_sz++;
    }

    char str[25];
    int op;
    while(~scanf("%s%d", str, &op)) {
        int ret = 0;
        if(op == 1)
            ret = linear_search(str);
        else if(op == 2)
            ret = binary_search(str, 0, dict_sz - 1);
        else if(op == 3)
            ret = index_search(str);
        else
            ret = hash_search(str);
        printf("%d %d\n", ret, cmp_cnt);
    }
}
