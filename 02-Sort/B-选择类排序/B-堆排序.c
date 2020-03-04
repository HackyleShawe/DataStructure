#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
注意：为了迎合二叉树层次遍历是从1开始，这里的数组统一把1作为第一个元素下标
*/
//使得a[s……m]之间的数成为一个大顶堆
void HeapAdjust(int a[], int s, int m)
{
	int temp, i;
	temp = a[s]; //①
	for (i = 2 * s; i <= m; i *= 2) //遍历i结点的左右孩子；②
	{
		if (i < m && a[i] < a[i + 1]) //③
		{
			++i;
		}
		if (temp >= a[i]) //④
		{
			break;
		}
		a[s] = a[i]; //⑤
		s = i;
	}
	a[s] = temp;
}

void HeapSort(int a[], int len)
{
	int i;
	for (i = len / 2; i > 0; i--) //将现在的待排序序列构建成一个大顶堆。为啥i从len的一半开始？
	{
		HeapAdjust(a, i, len);
	}
	for (i = len; i > 1; i--) //逐步将每个最大值的根结点与末尾元素交换，并且再调整其成为大顶堆。
	{
		//将堆顶记录和当前未经排序子序列的最后一个记录交换
		a[1] = a[1] ^ a[i];
		a[i] = a[1] ^ a[i];
		a[1] = a[1] ^ a[i];

		HeapAdjust(a, 1, i-1); //将剩下的又重新调整为大顶堆
	}
}

void RandomArray(int* array, int length)
{
	int i;
	srand((unsigned int)time(NULL));
	for (i = 1; i < length; i++) //堆排序中数组从1下标开始存第一个元素
	{
		array[i] = rand() % 100 + 1;
	}
}
void ShowArray(int* array, int length)
{
	int i;
	printf("\nThe Array is:");
	for (i = 1; i < length; i++) //堆排序中数组是从1开始存第一个元素的
	{
		printf("%d  ", array[i]);
	}
	printf("\n");
}

int main()
{
	int a[10];
	RandomArray(a, 10);
	ShowArray(a, 10);

	HeapSort(a, 9); //len=9？因为堆排序中数组是从下标1开始存第一个元素，即a[0]不存数或不参与排序；
	ShowArray(a, 10);
	return 0;
}
