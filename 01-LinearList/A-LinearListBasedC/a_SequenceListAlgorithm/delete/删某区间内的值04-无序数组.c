#include <stdio.h>
#include <stdlib.h>
#define N 10
/*
 * 函数功能：删除数组中元素值在某区间的元素
 * 输入：数组a，长度len, 要删除的元素值区间[x,y]
 * 输出：删除后的数组，返回数组长度
 * 算法：从头开始且相邻的双下标思想
 *  1.设定i遍历数组，k为符合条件个数；
 *  2.当元素不等于指定值时，将下标i的值赋值给下标i后移k个元素后的位置；
 */
int DeleteElement(int a[], int len, int x, int y)
{
	int k = 0;
	int i;
	for (i = 0; i < len; i++)
	{
		if (a[i] >= x && a[i] <= y)
		{
			k++;
		}
		else
		{
			a[i - k] = a[i];
		}
	}
	return len - k; //返回当前数组的长度
}

void PrintArray(int a[], int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%3d", a[i]);
	}
	printf("\n");
}
int main()
{
	int a[N] = { 0 };
	int i;
	int len = N;

	for (i = 0; i < N; i++)
	{
		a[i] = rand() % 50;
	}

	PrintArray(a, len);
	len = DeleteElement(a, len, 20, 40);
	PrintArray(a, len);
	return 0;
}