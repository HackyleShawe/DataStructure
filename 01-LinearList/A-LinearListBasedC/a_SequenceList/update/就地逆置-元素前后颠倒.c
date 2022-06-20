/*
 * 需求：将数组的所有元素前后颠倒，要求时间复杂度为O(1)
 */
#include <stdio.h>
#include <stdlib.h>
#define N 10
/*
 * 函数功能：数组元素就地逆置
 * 输入：数组a，长度len
 * 输出：逆置后的数组
 * 算法：遍历前半部分，把第i个数 与 第n-i-1个数交换
 */
void reverse(int a[], int len)
{
	int i,n;
	for (i = 0, n = len / 2; i < n; i++)
	{
		int tmp = a[i];
		a[i] = a[len - i - 1];
		a[len - i - 1] = tmp;
	}
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

	for (i = 0; i < N; i++)
	{
		a[i] = rand() % 50;
	}

	PrintArray(a, N);
	reverse(a, N);
	PrintArray(a, N);
	return 0;
}