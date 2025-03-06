/*
    给定算数表达式的中缀形式和后缀形式求前缀形式
    输入：两行，第一行是表达式的中缀形式，第二行是表达式的后缀形式
    输出：一行，表达式的前缀形式

    示例输入 1：
        A+B*C-D/E
        ABC*+DE/-
    示例输出 1：
        -+A*BC/DE

    示例输入 2:
        DBCAFEG
        DCBFGEA
    示例输出 2:
        ABDCEFG
*/

#include <stdio.h>
#include <string.h>
char a[10005], b[10005];

// 查找某个字符在字符串中的位置,返回下标 
int search(char x[], char y){
	int i = 1;
	while(x[i] != y) i++;
	return i;
}

//中序数组从 l 到 r, 后序数组从 l2 到 r2 
void dfs(int l, int r, int l2, int r2)
{
	if((l > r) || (l2 > r2)) return ; 
	printf("%c", b[r2]);//后序数组的最后一位,即为当前的根 
	int t = search(a, b[r2]);
	dfs(l, t - 1, l2, l2 + t - 1 - l);	
	dfs(t + 1, r, r2 - r + t, r2 - 1);
}

// 输入 中序和后序 -> 前序
// 注意输入的顺序
int main() {
	scanf("%s", a + 1);//读入中序排列 
	int n = strlen(a + 1);
	scanf("%s", b + 1);//读入后序排列
	dfs(1, n, 1, n);
	return 0;
}