//文件压缩-Huffman实现
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 32

struct tnode {					//Huffman树结构
	char c;		
	int weight;					//树节点权重，叶节点为字符和它的出现次数
	struct tnode *left,*right;
} ; 
int Ccount[128]={0};			//存放每个字符的出现次数，如Ccount[i]表示ASCII值为i的字符出现次数 
struct tnode *Root=NULL; 		//Huffman树的根节点
char HCode[128][MAXSIZE]={{0}}; //字符的Huffman编码，如HCode['a']为字符a的Huffman编码（字符串形式） 
int Step=0;						//实验步骤 
FILE *Src, *Obj;
	
void statCount();				//步骤1：统计文件中字符频率
void createHTree();				//步骤2：创建一个Huffman树，根节点为Root 
void makeHCode();				//步骤3：根据Huffman树生成Huffman编码
void atoHZIP(); 				//步骤4：根据Huffman编码将指定ASCII码文本文件转换成Huffman码文件

void print1();					//输出步骤1的结果
void print2(struct tnode *p);	//输出步骤2的结果 
void print3();					//输出步骤3的结果
void print4();					//输出步骤4的结果

int main()
{
	if((Src=fopen("input.txt","r"))==NULL) {
		fprintf(stderr, "%s open failed!\n", "input.txt");
		return 1;
	}
	if((Obj=fopen("output.txt","w"))==NULL) {
		fprintf(stderr, "%s open failed!\n", "output.txt");
		return 1;
	}
	scanf("%d",&Step);					//输入当前实验步骤 
	
	statCount();						//实验步骤1：统计文件中字符出现次数（频率）
	if(Step==1) 
		print1(); 			//输出实验步骤1结果	
	createHTree();						//实验步骤2：依据字符频率生成相应的Huffman树
	if(Step==2) 
		print2(Root); 		//输出实验步骤2结果	
	makeHCode();				   		//实验步骤3：依据Root为树的根的Huffman树生成相应Huffman编码
	if(Step==3) 
		print3(); 			//输出实验步骤3结果
	if(Step>=4) 
		atoHZIP(),print4(); 	//实验步骤4：据Huffman编码生成压缩文件，并输出实验步骤4结果	

	fclose(Src);
	fclose(Obj);

    return 0;
} 

//【实验步骤1】开始 

void statCount()
{
	Ccount[0] = 1;	// 题目要求
	char ch;
	while(( ch = fgetc(Src) ) != EOF) 
		if(ch != '\n')
			Ccount[ch]++;	// 统计字符出现次数
}

//【实验步骤1】结束

//【实验步骤2】开始

typedef struct tnode  node;
typedef struct tnode* nptr;
nptr arr[150];    // 存放 Huffman 树节点的数组
int sz = 0; // 数组大小

nptr newnode() {
    return (nptr)malloc(sizeof(node));
}

nptr getnode(char c, int weight) {
    nptr p = newnode();
    p -> c = c;
    p -> weight = weight;
    p -> left = NULL;
    p -> right = NULL;
    return p;
}

int cmp(const void *a, const void *b) {
    nptr x = *(nptr *)a, y = *(nptr *)b;
    // 权重不同，权重小的在后
    if(x -> weight != y -> weight)
        return y -> weight - x -> weight;
    // 权重相同且都是字符结点，字符小的在后
    if(x -> c >= 0 && y -> c >= 0)
        return y -> c - x -> c;
    // 权重相同且不都是非字符结点，后插入的在前
    // c 值越小插入时间越靠后
    return x -> c - y -> c;
}

void createHTree()
{
    // 创建单结点树
    for(int i = 0; i < 128; i++)
        if(Ccount[i] > 0) 
            arr[sz++] = getnode(i, Ccount[i]);

    int time = 0;
    while(sz > 1) {
        qsort(arr, sz, sizeof(nptr), cmp);
        nptr left = arr[sz - 1], right = arr[sz - 2];
        nptr p = getnode(--time, left -> weight + right -> weight);
        p -> left = left;
        p -> right = right;
        arr[sz - 2] = p;
        sz--;
    }

    Root = arr[0]; // 根结点
}

//【实验步骤2】结束

//【实验步骤3】开始

void preDfs(nptr p, char *code, int len) {
    if(p -> left == NULL && p -> right == NULL) {
        code[len] = '\0';
        strcpy(HCode[p -> c], code);
        return;
    }
    // 向左走，设置下一位为 0，记录一条左边
    code[len] = '0';
    preDfs(p -> left, code, len + 1);
    // 向右走，设置下一位为 1，记录一条右边
    code[len] = '1';
    preDfs(p -> right, code, len + 1);
}

void makeHCode()
{
    char code[32];
    preDfs(Root, code, 0); 
} 

//【实验步骤3】结束

//【实验步骤4】开始

// 存放二进制串
char binStr[100005];
void atoHZIP()
{
    Src = fopen("input.txt", "r");
    char ch;
    while((ch = fgetc(Src)) != EOF) 
        strcat(binStr, HCode[ch]);
    
    // 手动补空字符
    strcat(binStr, HCode[0]);
    int len = strlen(binStr);
    // 8 的倍数
    if(len % 8 != 0) {
        for(int i = len; i < len + 8 - len % 8; i++)
            binStr[i] = '0';
    }
    
    len = strlen(binStr);
    for(int i = 0; i < len; i += 8) {
        // 8 位二进制转为 1 字节
        unsigned char byte = 0;
        for(int j = 0; j < 8; j++) {
            byte <<= 1;
            if(binStr[i + j] == '1')
                byte |= 1;
        }
        printf("%x", byte);
        // 输出到文件
        fputc(byte, Obj);
    }
}

//【实验步骤4】结束

void print1()
{
	int i;
	printf("NUL:1\n");
	for(i=1; i<128; i++)
		if(Ccount[i] > 0)
			printf("%c:%d\n", i, Ccount[i]);
}

void print2(struct tnode *p)
{
	if(p != NULL){
		if((p->left==NULL)&&(p->right==NULL)) 
			switch(p->c){
				case 0: printf("NUL ");break;
				case ' ':  printf("SP ");break;
				case '\t': printf("TAB ");break;
				case '\n':  printf("CR ");break;
				default: printf("%c ",p->c); break;
			}
		print2(p->left);
		print2(p->right);
	}
}

void print3()
{
	int i;
	
	for(i=0; i<128; i++){
		if(HCode[i][0] != 0){
			switch(i){
				case 0: printf("NUL:");break;
				case ' ':  printf("SP:");break;
				case '\t': printf("TAB:");break;
				case '\n':  printf("CR:");break;
				default: printf("%c:",i); break;
			}
			printf("%s\n",HCode[i]);
		}
	}
} 

void print4()
{
	long int in_size, out_size;
	
	fseek(Src,0,SEEK_END);
	fseek(Obj,0,SEEK_END);
	in_size = ftell(Src);
	out_size = ftell(Obj);
	
	printf("\n原文件大小：%ldB\n",in_size);
	printf("压缩后文件大小：%ldB\n",out_size);
	printf("压缩率：%.2f%%\n",(float)(in_size-out_size)*100/in_size);
}
