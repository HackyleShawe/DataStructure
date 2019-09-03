/*

顺序查找(Sequential Search)又叫线性查找，是最基本的查找技术。

它的查找过程是：
	从表中第一个（或最后一个）记录开始，逐个进行记录的关键字和给定值比较，若某个记录的关键字和给定值相等，则查找成功，找到所查的记录；
	如果直到最后一个（或第一个）记录，其关键字和给定值比较都不等时，则表中没有所查的记录，查找不成功。
*/

/*===============================起始 分割线================================*/
/*
程序目的：
	理解线性查找
程序功能：
	使用动态随机数组实现线性查找
程序环境：
	VS 2017 X86 Debug
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//参数解释：线性表，长度，带查找的关键字
int SequentialSearch(int* a, int n, int key)
{
	int i;

	printf("待查找的键为：%d\n", key);
	printf("线性表为：\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
		if (a[i] == key)
		{
			return i;
		}
	}
	return 0;
}

void test()
{
	int n; //数组的长度
	int *a; //线性表
	int key; //待查找的数
	int i; //循环变量

	srand((unsigned int)time(NULL));

	n = rand() % 11 + 10; //数组的长度为[10,20]
	a = (int *)malloc(n * sizeof(int));
	
	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 101; //产生[0,100]之间的数
	}
	key = rand() % 101;

	int result = SequentialSearch(a, n, key);
	if (result)
	{
		printf("\n找到了！它的位置是：%d\n", result);

	}
	else
	{
		printf("\n没找到！\n");
	}
}

int main()
{
	test();
	system("pause");
	return 0;
}
/*===============================结束 分割线================================*/



/*===============================起始 分割线================================*/
//在上面的算法中，每次循环时都需要对i是否越界进行检查，即判断i是否小于n。
//还可以进行优化为：设置一个小兵，改用while循环。

//前提是，数组一开始时，对于a[0]就是没有利用的、空的。这样才能放下哨兵。

/*
程序目的：
	优化顺序（线性）查找的运行次数
程序功能：
	优化：for循环中的一些比较
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//参数解释：线性表，长度，带查找的关键字
int SequentialSearch(int* a, int n, int key)
{
	int i;

	a[0] = key;
	i = n;
	while (a[i] != key)
	{
		i--;
	}
	return i; //返回0则说明查找失败
}

void test()
{
	int n; //数组的长度
	int *a; //线性表
	int key; //待查找的数
	int i; //循环变量

	srand((unsigned int)time(NULL));

	n = rand() % 11 + 10; //数组的长度为[10,20]
	a = (int *)malloc(n * sizeof(int));

	a[0] = 0; //a[0]是哨兵，初始化为0

	for (i = 1; i <= n; i++)
	{
		a[i] = rand() % 101; //产生[0,100]之间的数
	}

	key = rand() % 101;
	printf("待查找的键为：%d\n数组长度为：%d, 数组为：\n", key, n);
	for (i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}

	int result = SequentialSearch(a, n, key);
	if (result)
	{
		printf("\n找到了！它的位置是：a[%d]\n", result);

	}
	else
	{
		printf("\n没找到！\n");
	}
}

int main()
{
	test();
	system("pause");
	return 0;
}

/*===============================结束 分割线================================*/