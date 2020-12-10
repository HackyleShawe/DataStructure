/*
 * 需求：
 *   1. 一个数组a，长度为len。将下标为[0, k]与下标为[k+1,len-1]之间的元素交换。
 *   2. 例如，数组a[6]={1,2,3,4,5,6}，将前三个与后三个交换后，a[6]={4,5,6,1,2,3};
 *
 * 算法：将数组就地逆置，再将[0,k]与[k+1,len-1]之间的元素就地逆置
 */
#include <stdio.h>
#include <stdlib.h>
#define N 10
/*
 * 函数功能：数组元素的部分互换
 * 输入：数组a，长度len，要逆置的范围[left,right]
 * 输出：逆置后的数组
 */
void PartReverse(int a[], int len, int left, int right)
{
	int mid = (left + right) / 2;
	int i;
	while (left <= mid && right >= mid)
	{
		int tmp = a[left];
		a[left] = a[right];
		a[right] = tmp;
		left++;
		right--;
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
	int part = 4;
	for (i = 0; i < N; i++)
	{
		a[i] = rand() % 50;
	}

	PrintArray(a, N);

	PartReverse(a, N, 0, N-1);
	PartReverse(a, N, 0, part);
	PartReverse(a, N, part+1, N - 1);

	PrintArray(a, N);
	return 0;
}