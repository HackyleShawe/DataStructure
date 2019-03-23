#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* 快速排序
Algorithm Summary：把第i++个数(称为基数)以递归的方法(从右向左的第一个小于基数的数、从左向右的第一个大于基数的数，互换)，
	把基数放在最后排好序了的位置；

*/
void QuickSort(int *a, int left, int right)
{
	int i, j;
	int t = 0;

	if (left < right)
	{
		i = left; j = right;
		t = a[i]; //"第i++"个数；

		while (i != j)
		{
			while (a[j] >= t && i<j) //顺序很重要，要先从右边开始找
				j--;   //while条件中的"a[j]>=t"中必须要有等于号才正确；
			
			while (a[i] <= t && i<j) //再找左边的 
				i++;
			
			if (i<j) //交换两个数在数组中的位置 
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
		a[left] = a[i];
		a[i] = t; //一层递归后，把第i++个数放在初次最终的位置；

		QuickSort(a, left, i - 1); //继续处理左边的，这里是一个递归的过程 
		QuickSort(a, i + 1, right); //继续处理右边的 ，这里是一个递归的过程 
	}
}

void RandomArray(int *array, int length)
{
	int i;
	srand((unsigned int)rand(NULL));
	for (i = 0; i < length; i++)
	{
		array[i] = rand() % 100 + 1;
	}
}
void ShowArray(int *array, int length)
{
	int i;
	printf("\nThe Array is:");
	for (i = 0; i < length; i++)
	{
		printf("%d  ", array[i]);
	}
	printf("\n");
}

int main()
{
	int a[10];// = { 2,4,1,6,9,20,55,23,132,0 };
	RandomArray(a, 10);
	ShowArray(a, 10);

	QuickSort(a, 0, 9);

	ShowArray(a, 10);
	system("pause");
	return 0;
}


