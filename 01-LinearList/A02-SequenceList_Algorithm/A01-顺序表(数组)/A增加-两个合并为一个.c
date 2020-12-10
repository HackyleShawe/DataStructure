/*
 * 需求：将两个有序数组合并为一个
 */


#include <stdio.h>
#define M 3
#define N 3

/*
 * 函数功能：合并两个有序数组
 * 输入：两个有序数组(a,b)，存储合并后的数组(c)
 * 输出：无
 * 算法：
 *  1.同时遍历两个有序数组，将符合条件的下标前进，不符合条件的下标不动；
 *  2.看那个数组还有剩余，将剩余的依次顺序加入到新的数组即可；
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
