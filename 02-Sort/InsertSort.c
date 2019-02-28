//InsertSort：直接插入语排序

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define LEN 10

/*	直接插入排序
Algorithm Summary：进行N-1回：把第i++个数插入到前i++个已经排好序了的数中；
	操作：找、挪、插

*/
void InsertSort(int *a, int length)
{
	int i, j;
	int temp = 0;

	for (i = 1; i < length; i++) //第一个元素认为已经排序了，从第二个元素开始拿出去排；
	{
		temp = a[i];
		for (j = i - 1; j >= 0 && temp < a[j]; j--) //找：在j--里寻找该数存在的合适位置；
		{
			a[j + 1] = a[j]; //挪：
		}
		a[j + 1] = temp; //插：这里为什么要加1呢？因为在上一个for里多减了一次1；
	}
}

void GetArray(int *a, int length)
{
	int i; //循环变量
	srand((unsigned)time(0)); //每次都随机得到
	for (i = 0; i < length; i++)
	{
		a[i] = rand() % 100 + 1; //取得100以下的整数
	}
}
void ShowArray(int *a, int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		printf("%5d", a[i]);
	}
	putchar('\n');
}
int main()
{
	int a[LEN] = { 0 };
	GetArray(a, LEN);
	ShowArray(a, LEN);

	InsertSort(a, LEN);

	ShowArray(a, LEN);

	system("pause");
	return 0;
}