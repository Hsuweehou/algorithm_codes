#include <stdio.h>
#include <string>
#include <cstring>
 
//1、将一整数逆序后放入一数组中（要求递归实现）
void convert(int *result, int n)
{
	if(n>=10)
		convert(result+1, n/10);
	*result = n%10;	
}
//2、删除串中指定的字符
void delChar(char *str, char c)
{
	int i, j=0;
	for(i=0; str[i]; i++)
		if(str[i]!=c) str[j++]=str[i];
	str[j] = '\0';
}
 
//3、递归实现回文判断（如：abcdedbca就是回文，判断一个面试者对递归理解的简单程序）
int find(char *str, int n) 
{
	if(n<=1)	
		return 1;
	else if(str[0]==str[n-1])	
		return find(str+1, n-2);
	else
		return 0;
}
 
//4、组合问题（从M个不同字符中任取N个字符的所有组合）
void find(char *source, char *result, int n) 
{
	if(n==1) 
	{
		while(*source)
			printf("%s%c\n", result, *source++);
	} 
	else 
	{
		int i, j;
		for(i=0; source[i] != 0; i++);
		for(j=0; result[j] != 0; j++);
		for(; i>=n; i--) 
		{
			result[j] = *source++;
			result[j+1] = '\0';
			find(source, result, n-1);
		}
	}
}
 
//5、分解成质因数(如435234=251*17*17*3*2，据说是华为笔试题)
void prim(int m, int n)
{
	if(m>n) 
	{
		while(m%n != 0) n++;
		m /= n;
		prim(m, n);
		printf("%d*", n);
	}
}
 
//6、寻找迷宫的一条出路，o：通路； X：障碍。（大家经常谈到的一个小算法题）
#define MAX_SIZE  8
int H[4] = {0, 1, 0, -1}; 
int V[4] = {-1, 0, 1, 0};           
char Maze[MAX_SIZE][MAX_SIZE] = {
	{'X','X','X','X','X','X','X','X'},
	{'o','o','o','o','o','X','X','X'},
	{'X','o','X','X','o','o','o','X'},
	{'X','o','X','X','o','X','X','o'},
	{'X','o','X','X','X','X','X','X'},
	{'X','o','X','X','o','o','o','X'},
	{'X','o','o','o','o','X','o','o'},
	{'X','X','X','X','X','X','X','X'}};
 
void FindPath(int X, int Y) 
{
	if(X == MAX_SIZE || Y == MAX_SIZE) 
	{
		for(int i = 0; i < MAX_SIZE; i++)
			for(int j = 0; j < MAX_SIZE; j++)
				printf("%c%c", Maze[i][j], j < MAX_SIZE-1 ? ' ' : '\n');
	}
	else 
		for(int k = 0; k < 4; k++) 
		if(X >= 0 && Y >= 0 && Y < MAX_SIZE && X < MAX_SIZE && 'o' == Maze[X][Y]) 
		{
			Maze[X][Y] = ' ';
			FindPath(X+V[k], Y+H[k]);
			Maze[X][Y] ='o'; 
		}
}
//7、求网格中的黑点分布。现有6*7的网格，在某些格子中有黑点，已知各行与各列中有黑点的点数之和，请在这张网格中画出黑点的位置。
#define ROWS 6
#define COLS 7
int iPointsR[ROWS] = {2, 0, 4, 3, 4, 0};           // 各行黑点数和的情况
int iPointsC[COLS] = {4, 1, 2, 2, 1, 2, 1};        // 各列黑点数和的情况
int iCount, iFound;
int iSumR[ROWS], iSumC[COLS], Grid[ROWS][COLS];
 
int Set(int iRowNo) 
{
	if(iRowNo == ROWS)
	{ 
		for(int iColNo=0; iColNo < COLS && iSumC[iColNo]==iPointsC[iColNo]; iColNo++) 
		{
			if(iColNo == COLS-1)
			{
				printf("\nNo.%d:\n", ++iCount); 
				for(int i=0; i < ROWS; i++)
					for(int j=0; j < COLS; j++)
						printf("%d%c", Grid[i][j], (j+1) % COLS ? ' ' : '\n');
				iFound = 1;	// iFound = 1，有解
			}
		}
	} 
	else
	{
		for(int iColNo=0; iColNo < COLS; iColNo++) 
		{
			if(iPointsR[iRowNo] == 0) { 
				Set(iRowNo + 1);
			}
			else if(Grid[iRowNo][iColNo]==0) 
			{ 
				Grid[iRowNo][iColNo] = 1; 
				iSumR[iRowNo]++; iSumC[iColNo]++;
				if(iSumR[iRowNo]<iPointsR[iRowNo] && iSumC[iColNo]<=iPointsC[iColNo])
					Set(iRowNo);
				else if(iSumR[iRowNo]==iPointsR[iRowNo] && iRowNo < ROWS)
					Set(iRowNo + 1);
				Grid[iRowNo][iColNo] = 0;
				iSumR[iRowNo]--; 
				iSumC[iColNo]--;
			}
		}
	}
	return iFound;   		// 用于判断是否有解
}
 
//8、有4种面值的邮票很多枚，这4种邮票面值分别1, 4, 12, 21，现从多张中最多任取5张进行组合，求取出这些邮票的最大连续组合值。
#define N 5
#define M 5
int k, Found, Flag[N];
int Stamp[M] = {0, 1, 4, 12, 21};
 
// 在剩余张数n中组合出面值和Value
int Combine(int n, int Value)
{
	if(n >= 0 && Value == 0) 
	{
		Found = 1;
		int Sum = 0;
		for(int i=0; i<N && Flag[i] != 0; i++) 
		{
			Sum += Stamp[Flag[i]];
			printf("%d ", Stamp[Flag[i]]);
		}
		printf("\tSum=%d\n\n", Sum);
	}
	else
	{
		for(int i=1; i<M && !Found && n>0; i++)
		{
			if(Value-Stamp[i] >= 0) {
				Flag[k++] = i;
				Combine(n-1, Value-Stamp[i]);
				Flag[--k] = 0;
			}
		}
	}
	return Found;
}
 
//9、大整数数相乘的问题。
void Multiple(char A[], char B[], char C[])
{
	int TMP, In=0, LenA=-1, LenB=-1;
	while(A[++LenA] != '\0');
	while(B[++LenB] != '\0');
	int Index, Start = LenA + LenB - 1;
	for(int i=LenB-1; i>=0; i--) 
	{
		Index = Start--;
		if(B[i] != '0') 
		{
			for(int In=0, j=LenA-1; j>=0; j--) 
			{
				TMP = (C[Index]-'0') + (A[j]-'0') * (B[i] - '0') + In;
				C[Index--] = TMP % 10 + '0';
				In = TMP / 10;
			}
			C[Index] = In + '0';
		}
	}
}
 
//10、求最大连续递增数字串（如“ads3sl456789DF3456ld345AA”中的“456789”）
int GetSubString(char *strSource, char *strResult) 
{
	int iTmp=0, iHead=0, iMax=0;
	for(int Index=0, iLen=0; strSource[Index]; Index++) 
	{
		if(strSource[Index] >= '0' 
			&& strSource[Index] <= '9' 
			&& strSource[Index-1] > '0' 
			&& strSource[Index] == strSource[Index-1]+1) 
		{
				iLen++;// 连续数字的长度增1 
		} 
		else // 出现字符或不连续数字
		{
			if(iLen > iMax) 
			{
				iMax = iLen;
				iHead = iTmp; 
			}        
			// 该字符是数字，但数字不连续
			if(strSource[Index] >= '0' && strSource[Index] <= '9') 
			{ 
				iTmp = Index; 
				iLen = 1; 
			}
		}    
	}
	for(iTmp=0 ; iTmp < iMax; iTmp++)// 将原字符串中最长的连续数字串赋值给结果串
	{
		strResult[iTmp] = strSource[iHead++];
	}
	strResult[iTmp]='\0';
	return iMax;// 返回连续数字的最大长度
}
//
void show()  
{
	printf("//\n");
	printf("请选择算法:\n");
	printf("[ 1 ]: 将一整数逆序后放入一数组中\n");
	printf("[ 2 ]: 删除串中指定的字符\n");
	printf("[ 3 ]: 递归实现回文判断\n");
	printf("[ 4 ]: 从M个不同字符中任取N个字符的所有组合\n");
	printf("[ 5 ]: 分解成质因数\n");
	printf("[ 6 ]: 寻找迷宫的一条出路\n");
	printf("[ 7 ]: 求网格中的黑点分布\n");
	printf("[ 8 ]: 求取出这些邮票的最大连续组合值\n");
	printf("[ 9 ]: 大整数数相乘的问题\n");
	printf("[ 10 ]: 求最大连续递增数字串\n\n");
} 
 
int main()
{
	show();
	int choice;  
	while (scanf("%d", &choice)) 
	{
		switch (choice)
		{
		case 1:
			{
				int n = 123456789, result[20]={};
				convert(result, n);
				printf("%d:", n);
				for(int i=0; i<9; i++)
					printf("%d", result[i]);
			}
			break;
		case 2:
			{
				char str[] = "abcdefgh";// 注意，此处不能写成char *str = "abcdefgh";
				printf("%s\n", str);
				delChar(str, 'c');
				printf("%s\n", str);
			}
			break;
		case 3:
			{
				char *str = "abcdedcba";
				printf("%s: %s\n", str, find(str, strlen(str)) ? "Yes" : "No");
			}
			break;
		case 4:
			{
				int const n = 3;
				char *source = "ABCDE", result[n+1] = {0};
				if(n>0 && strlen(source)>0 && n<=strlen(source))
					find(source, result, 3);
			}
			break;
		case 5:
			{
				int n = 435234;
				printf("%d=", n);
				prim(n, 2);
			}
			break;
		case 6:
			{
				FindPath(1,0);
			}
			break;
		case 7:
			{
				if(!Set(0))
					printf("Failure!"); 
			}
			break;
		case 8:
			{
				for(int i=1; Combine(N, i); i++, Found=0);
			}
			break;
		case 9:
			{
				char A[] = "21839245554444448880088888889";
				char B[] = "38888888888899999999999999988";
				char C[sizeof(A) + sizeof(B) - 1];
 
				for(int k=0; k<sizeof(C); k++)
					C[k] = '0';
				C[sizeof(C)-1] = '\0';
 
				Multiple(A, B, C);
				for(int i=0; C[i] != '\0'; i++)
					printf("%c", C[i]);
			}
			break;
		case 10:
			{
				char strSource[]="ads3sl456789DF3456ld345AA"; 
				char strResult[sizeof(strSource)];
				printf("Len=%d, strResult=%s \nstrSource=%s\n", 
					GetSubString(strSource, strResult), 
					strResult, 
					strSource);
			}
			break;
		}
		show();
	}
 
	system("pause");
 
	return 0;
}