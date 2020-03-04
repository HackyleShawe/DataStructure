#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*	冒泡排序
Algorithm Summary：进行N-1回；每回把前length-(i++)个数一一相邻比较并交换；
	第一层for：要进行N-1回； 第二层for：每次把左右的数比较并交换；
*/
void BubbleSort(int *array, int length)
{
	int i, j;
	int temp = 0;
	for (i = 0; i < length - 1; i++) //要进行N-1回；
	{
		for (j = 0; j < length - 1 - i; j++) //每次把左右的数比较并交换，已经比较过了的不再进行；
		{								    //length-i会使数组发生溢出！
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	/*
	凡是下标从0开始，就要减去一个1；
	1,第一层for：只需要把前面length-1个拿出来沉就可以了；
	2,第二层for：后面的length-1-i个已经被排序好了；并且完成这一次循环后都把最大的沉到最下面了；
	*/
}
void BubbleSortA(int *array, int length)
{
	int i, j,temp = 0 ;
	int flag = 1;
	for (i = 0; i < length-1 && flag; i++) //要进行N-1回；
	{
		flag = 0; //如果某一回中的每一次都没有进行过交换，则说明数据已经是有序的了，则停止算法；
		for (j = 0; j < length - 1 - i; j++) //每次把左右的数比较并交换，已经比较过了的不再进行；
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = 1;
			}
		}
	}
}

void BubbleSortC(int *a, int len)
{
	int i, j;
	if (len == 0 || len<2)
	{
		return;
	}
	for (i = len - 1; i>0; i--)
	{
		for (j = 0; j<i; j++)
			if (a[j]>a[j + 1])
			{
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
	}
}

/* Reflect Myself
1,为什么两个函数中的第二层for中都是"j<length-1-*"？
	因为对N个数排序，只需要排N-1个数，另外一个一定不用排；





*/

void RandomArray(int *array, int length)
{
	int i;
	time_t ts;
	srand((unsigned int)rand(&ts));
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
	int a[10]; // = {2,4,1,6,9,20,55,23,132,0}
	RandomArray(a, 10);
	ShowArray(a, 10);

	BubbleSortA(a,10);
	ShowArray(a, 10);
	system("pause");
	return 0;
}
