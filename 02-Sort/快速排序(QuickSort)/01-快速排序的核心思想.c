/*===============================起始 分割线================================*/
/*
程序目的：
	展示快速排序的核心算法
程序功能：
	对n个数进行快速排序算法排序
程序环境：
	VS2019 x86 debug
*/

/*
注意：
1、本算法思想和部分代码学习与《大话数据结构》，建议你先去看原书。
2、那为什么还要看我的代码呢？这是因为，我提供了直接可以运行的代码，同时还修改了原书中的一些错误，更便于你理解核心算法和代码的含义。
3、如果你在源码中看不懂，请先去问度娘、Google，再去研究一下原书；当然，也欢迎骚扰我。
*/

/*===============================结束 分割线================================*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
程序功能：
	返回数组a[low,high]中的基数最终排好序放置的位置；
*/
int partition(int a[], int low, int high)
{
	int pivot_key; //称为基数、枢轴记录(数)

	pivot_key = a[low]; //以传入数组的第一个元素作基数

	while (low < high) //从数组的两端分别向中间扫描
	{
		while (low < high && a[high] >= pivot_key) //当队尾的元素大于等于基数时,向前挪动high指针
		{
			high--;
		}
		//一旦找到比基数小的数，将该数放到最左端
		a[low] = a[low] ^ a[high];
		a[high] = a[low] ^ a[high];
		a[low] = a[low] ^ a[high];

		while (low < high && a[low] <= pivot_key) //从左往右
		{
			low++;
		}
		//一旦找到比基数大的数，将该数放到最右端
		a[low] = a[low] ^ a[high];
		a[high] = a[low] ^ a[high];
		a[low] = a[low] ^ a[high];
	}
	a[low] = pivot_key;
	return low; //返回基数所在的位置
}

void QuickSort(int a[], int low, int high)
{
	int pivot; //基数、枢轴数 的位置
	if (low < high)
	{
		pivot = partition(a, low, high); //将数组a[low……high]一分为二，算出基数的位置
		QuickSort(a, low, pivot - 1);
		QuickSort(a, pivot + 1, high);
	}
}

void GetRandomArray(int a[], int len)
{
	int i;
	srand((unsigned int)time(NULL));
	for (i = 0; i < len; i++)
	{
		a[i] = rand();
	}
}
void ShowArray(int a[], int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int* a = NULL;
	int n = 100;

	a = (int*)malloc(sizeof(int) * n);
	GetRandomArray(a, n);
	ShowArray(a, n);
	QuickSort(a, 0, n - 1);
	ShowArray(a, n);
	return 0;
}
