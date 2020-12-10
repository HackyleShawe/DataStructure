
#include <stdio.h>
#include <stdlib.h>

/*
 * 函数功能：删除有序表中的重复值 
 * 输入：有序表，长度
 * 输出：删除重复值后的有序表、删除后的有序表长度
 * 算法：从头开始且相邻的双下标
 *  1.遍历，当第i个和第i++个数不相同时，将该数赋值给k
 *  2.将最后一个元素赋值给k，因为最后一个元素永远不会和后面的产生重复
 */
int DeleteRepeate(int a[], int len)
{
	int i = 0, k = 0; //i变量用于遍历数组，k变量用于接收符合条件的元素下标
	for (i = 0; i < len-1; i++)
	{
		if (a[i] != a[i+1])
		{
			a[k++] = a[i];
		}
	}
	a[k++] = a[i];
	return k;
}

int main()
{
	int a[15] = { 1,2,2,2,2,3,3,3,4,4,5,9,9,9,9 };
	int i, len;
	len = DeleteRepeate(a, 15);
	for (i = 0; i < len; i++)
	{
		printf("%5d", a[i]);
	}
	return 0;
}
