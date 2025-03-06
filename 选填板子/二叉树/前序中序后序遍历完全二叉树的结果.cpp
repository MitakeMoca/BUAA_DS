/*
    已知某完全二叉树采用顺序存储结构，给定结点的存放次序
    求该二叉树的前序序列、中序序列和后序序列
    输入：一个字符串表示二叉树对应的各个节点
    输出：三行，分别代表前序序列、中序序列和后序序列

    示例输入：
        ABCDEFGHIJ

    示例输出：
        ABDHIEJCFG
        HDIBJEAFCG
        HIDJEBFGCA
*/

#include <stdio.h>
#include <string.h>

int read() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

// 数组代替二叉树
char str[10005];
int n;

void preorder(int i) {
    if(i >= n)
        return;
    printf("%c", str[i]);
    preorder(2 * i + 1);
    preorder(2 * i + 2);
}

void midorder(int i) {
    if(i >= n)
        return;
    midorder(2 * i + 1);
    printf("%c", str[i]);
    midorder(2 * i + 2);
}

void postorder(int i) {
    if(i >= n)
        return;
    postorder(2 * i + 1);
    postorder(2 * i + 2);
    printf("%c", str[i]);
}

int main() {
    gets(str);
    n = strlen(str);

    preorder(0);
    puts("");

    midorder(0);
    puts("");

    postorder(0);
    puts("");

    return 0;
}