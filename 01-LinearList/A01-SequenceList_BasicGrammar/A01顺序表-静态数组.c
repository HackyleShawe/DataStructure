/*
写在前面：
	1. 在顺序表中，顺序表也分为静态顺序表和动态顺序表，它的本质就是静态数组和动态数组。
	2. 在实际编程开发中，几乎不会使用所谓的顺序表，而是直接使用数组，所以，这里不再讲解顺序表的一些列操作。
	3. 只要牢牢把握住：顺序表即数组，就可以了。
*/

#include <stdio.h>
#include <stdlib.h>
#define N 10

int main()
{
	int a[N]; //申明一个一维数组
	int b[N][N]; //申明一个二维数组
	int i, j;

	//一维数组
	for (i = 0; i < N; i++)
	{
		a[i] = i * 10;
	}

	for (i = 0; i < N; i++)
	{
		printf("%3d", a[i]);
	}
	printf("\n");

	//二维数组
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			b[i][j] = i + j;
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%3d", b[i][j]);
		}
		printf("\n");
	}

	return 0;
}