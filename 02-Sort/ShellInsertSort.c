//Shell插入排序：ShellInsertSort

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define LEN 10

/*  Shell插入排序
Algorithm Summary：
	进行for(d=length/2;d>0;d /=2)回;
	每回以d为间隔进行直接插入排序；
*/
void ShellInsertSort(int *a, int length)
{
	int i, j, d; //d是增量，每次减半
	int temp;

	for (d = length / 2; d > 0; d /= 2)
	{
		for (i = d; i < length; i+=d)
		{
			temp = a[i];
			for (j = i - d; j >= 0 && temp<a[j]; j -= d) //以d为间隔找到合适的插入位置；
			{
				a[d + j] = a[j]; //挪
			}
			a[d + j] = temp; //插
		}
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
		printf("%3d", a[i]);
	}
	putchar('\n');
}
int main()
{
	int a[LEN] = { 0 };
	GetArray(a, LEN);
	ShowArray(a, LEN);

	ShellInsertSort(a, LEN);

	ShowArray(a, LEN);

	system("pause");
	return 0;
}