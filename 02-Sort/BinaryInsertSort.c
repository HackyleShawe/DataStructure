//二分插入排序：BinaryInsertSort
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define LEN 10

/*  二分直接插入排序
	Algorithm Summary：进行N-1回：把第i++个数，在前i++个有序数中用二分查找的方式，找到这个数应该插入的位置；
	操作：找、挪、插

相比直接插入排序的优势：在"找"的操作哪里节约了时间和步骤；
*/

void BinaryInsertSort(int *a, int length)
{
	int right, mid, left;
	int i, j, temp;

	for (i = 1; i < length; i++) //从第一个数起，因为第一个数总是已排好序
	{
		temp = a[i];
		left = 0, right = i - 1;
		while (left <= right) //找：在前i++个数中以二分查找法查找该数应被放的位置是:left或right；
		{
			mid = (left + right)/2;
			if (temp < a[mid])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		for (j = i - 1; j > right; j--)
		{
			a[j + 1] = a[j];
		}
		a[left] = temp; //插；这里是left？——不理解就画图演算一下；
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

	BinaryInsertSort(a, LEN);

	ShowArray(a, LEN);

	system("pause");
	return 0;
}