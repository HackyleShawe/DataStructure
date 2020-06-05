二维动态数组的使用方式：
a.声明：int **a;
b.给内存：a=(int **)malloc(二维数的行数 * seizeof(int*));
	for(i=0;i<二维数组的行数;i++)  
		a[i]=(int *)malloc(每行有多少个元素 * sizeof(int));
c.即可以如常规的二维数组使用；


/*===============================Start 分割线================================*/
//动态的二维数组（最原始实现）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h> //必不可少头文件
#include <stdlib.h> //必不可少头文件

void GetRandomNumber(int** a, int n)
{
	srand((unsigned int)time(NULL));
	int i, j;
	for (i = 0; i < n; i++)
	{
		a[i] = (int*)malloc(sizeof(int) * n); //表明每行有n个元素位置
		for (j = 0; j < n; j++)
		{
			a[i][j] = rand()%100;
		}
	}
}
void show(int** a, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d  ", a[i][j]);
		}
		printf("\n第%d行完毕！\n", i+1);
	}
}

int main()
{
	int n = 100;
	int** a; //申明一个二维数组指针、二维指针变量

	a = (int**)malloc(sizeof(int*) * n); //表明二维数组总共有n行

	GetRandomNumber(a, n);
	show(a, n);
	return 0;
}
/*===============================End 分割线=================================*/



/*===============================Start 分割线================================*/
//二维动态数组要逻辑严密地使用
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitArray(char** a, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		a[i] = (char*)malloc(sizeof(char) * n);
		if (a[i] == NULL) //如果没有判空操作，上一行代码则会发出警告：“取消对NULL指针的引用”
		{
			return;
		}
		for (j = 0; j < n; j++)
		{
			a[i][j] = 'a';
		}
	}
}
void ShowArray(char** a, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%c ", a[i][j]);
		}
		printf("\n一行输出完了\n");
	}
}
int main()
{
	char** a;
	int n = 100;

	a = (char**)malloc(sizeof(char*) * n); //这里千万不能写为” sizeof(char) * n”!!!
	InitArray(a, n);
	ShowArray(a, n);

	return 0;
}
/*===============================End 分割线=================================*/



/*===============================Start 分割线================================*/
//释放二维动态数组内存
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitArray(char** a, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		a[i] = (char*)malloc(sizeof(char) * n);
		if (a[i] == NULL) //如果没有判空操作，上一行代码则会发出警告：“取消对NULL指针的引用”
		{
			return;
		}
		for (j = 0; j < n; j++)
		{
			a[i][j] = 'a';
		}
	}
}
void ReleaseArray(char** a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		free(*(a + i));
	}
}
void ShowArray(char** a, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%c ", a[i][j]);
		}
		printf("\n一行输出完了\n");
	}
}
int main()
{
	char** a;
	int n = 100;

	a = (char**)malloc(sizeof(char*) * n);
	InitArray(a, n);
	ShowArray(a, n);
	ReleaseArray(a, n);

	return 0;
}
/*===============================End 分割线=================================*/



/*===============================Start 分割线================================*/
//区分行列的动态二维数组
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int** a;
	int i, j;
	int row, column; //行，列
	row = 2; column = 3;
	/*
	2行3列为：
	第一行第一列	第一行第二列
	第二行第一列	第二行第二列
	*/

	a = (int**)malloc(sizeof(int*) * row);
	for (i = 0; i < row; i++)
	{
		a[i] = (int*)malloc(sizeof(int) * column);
		for (j = 0; j < column; j++)
		{
			a[i][j] = i * j;
		}
	}

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
/*
输出：
0 0 0
0 1 2
*/
/*===============================End 分割线=================================*/

