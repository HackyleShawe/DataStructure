#include <stdio.h>
#define N 10
/*
 * 函数功能：删除数组中元素值在某区间的元素
 * 输入：数组a，长度len, 要删除的元素值区间[x,y]
 * 输出：删除后的数组，返回数组长度
 * 算法：
 *  1.由于是有序，向右找第一个大于x的，记为left; 向左找第一个小于y的,记为right;
 *  2.将这段元素删除，只需要将后面的元素前移
 */
int DeleteElement(int a[], int len, int x, int y)
{
	int left = 0, right = len - 1;

	//向右找第一个大于x的
	while (a[left] < x)
	{
		left++;
	}
	//向左找第一个小于y的
	while (a[right] > y)
	{
		right--;
	}
	right++; //right如果不前移一位，会出现临界值问题

	while (right < len)
	{
		a[left++] = a[right++];
	}

	return left; //删除操作执行完毕后的数组长度
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
		a[i] = i * 5;
	}

	PrintArray(a, len);
	len = DeleteElement(a, len, 20, 40);
	PrintArray(a, len);
	return 0;
}