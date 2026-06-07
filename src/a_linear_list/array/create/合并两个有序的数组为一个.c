#include <stdio.h>
#define M 3
#define N 3

/*
 * 函数功能：合并两个有序数组
 * 输入：两个有序数组(a,b)，存储合并后的数组(c)
 * 输出：无
 * 算法：
 *  用两个指针分别指向两个数组起点，比较元素大小，小的放入结果数组，对应指针后移；
 *  剩余元素直接追加；
 *  时间复杂度 O (m+n)，空间 O (m+n)。
 */
void MergeSortedArray(int a[], int b[], int c[])
{
	int i = 0, j = 0;
	int k = 0;
	while (i < M && j < N)
	{
		if (a[i] > b[j])
		{
			c[k++] = b[j++];
		}
		else
		{
			c[k++] = a[i++];
		}
	}
	while (i < M)
	{
		c[k++] = a[i++];
	}
	while (j < N)
	{
		c[k++] = b[j++];
	}
}
int main()
{
	int a[M] = { 1,4,9 };
	int b[N] = { 5,8,10 };
	int c[M + N] = { 0 };
	MergeSortedArray(a, b, c);

	for (int i = 0; i < M + N; i++)
	{
		printf("%3d", c[i]);
	}
	return 0;
}
