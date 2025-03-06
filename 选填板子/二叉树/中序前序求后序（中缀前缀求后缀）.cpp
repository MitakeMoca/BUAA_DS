/*
    给定算数表达式的中缀形式和前缀形式求后缀形式
    输入：两行，第一行是表达式的中缀形式，第二行是表达式的前缀形式
    输出：一行，表达式的后缀形式

    示例输入 1：
        A+B*C-D/E
        -+A*BC/DE
    示例输出 1：
        ABC*+DE/-

    示例输入 2:
        DBCAFEG
        ABDCEFG
    示例输出 2:
        DCBFGEA

*/

#include <stdio.h>
#include <string.h>

//求后序遍历
char a[10005], b[10005], c[10005];
int num; 

// 查找 y 在 x 里的位置
int search(char x[], char y) {
	int i = 0;
	while(x[++i] != y);
	return i;
} 
void dfs(int l, int r, int l2, int r2) {
	if((l > r) || (l2 > r2)) return ;
	c[num] = b[l2];
    num--;
	int t = search(a, b[l2]);
	dfs(t + 1, r, r2 + t + 1 - r, r2); // 先搜右子树
	dfs(l, t - 1, l2 + 1, l2 + t - l); // 再搜左子树 
}

// 输入 中序和前序 -> 后序
// 注意输入的顺序
int main() {
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	num = strlen(a + 1);
	int n = num;
	dfs(1, n, 1, n);
	printf("%s",c + 1);
	return 0;
}