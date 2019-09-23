/*===============================起始 分割线================================*/
/*
程序功能：
	优化递归操作，将递归转化为循坏

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



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LENGTH_INSERT_SORT 7
/*
程序功能：
	返回数组a[low,high]中，基数最终排好序放置的位置；
*/
int partition(int a[], int low, int high)
{
	int pivot_key; //称为基数、枢轴记录(数)
	int m = low + (high - low) / 2; //计算数组中间的元素的下标
	if (a[low] > a[high]) //交换左端与右端数据，保证左端较小
	{
		a[low] = a[low] ^ a[high];
		a[high] = a[low] ^ a[high];
		a[low] = a[low] ^ a[high];
	}
	if (a[m] > a[high]) //交换中间与右端数据，保证中间较小
	{
		a[m] = a[m] ^ a[high];
		a[high] = a[m] ^ a[high];
		a[m] = a[m] ^ a[high];
	}
	if (a[m] < a[low]) //交换中间与左端数据，保证左端较小
	{
		a[m] = a[m] ^ a[low];
		a[low] = a[m] ^ a[low];
		a[m] = a[m] ^ a[low];
	}

	pivot_key = a[low]; /*此时a[low]已经为整个序列左中右三个关键字的中间值。用子表的第一个记录作枢轴记录*/

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

void InsertSort(int a[], int len)
{
	int i, j;
	int t;
	for (i = 1; i < len; i++) //从第二个数开始，因为第一个数无论如何都是有序的；其后的每个元素都要拿出来去插入
	{
		if (a[i - 1] > a[i]) //因为前“i-1”个数都是有序的，若第i个数大于第“i-1”个数，则不用再操作
		{
			t = a[i];
			for (j = i - 1; j >= 0 && t < a[j]; j--) //向前找
			{
				a[j + 1] = a[j]; //向前挪
			}
			a[j + 1] = t; //插入；这里为什么要加1呢？因为在上一个for里多减了一次1；
		}
	}
}

void QuickSort(int a[], int low, int high)
{
	int pivot; //基数、枢轴数 的位置
	if ((high - low) > MAX_LENGTH_INSERT_SORT)
	{
		while (low < high) //用循坏来替代递归
		{
			pivot = partition(a, low, high); //将数组a[low……high]一分为二，算出基数的位置
			QuickSort(a, low, pivot - 1);
			low = pivot + 1;  //相当于执行QuickSort(a, pivot + 1, high);
		}
	}
	else //当待排序的元素个数少于MAX_LENGTH_INSERT_SORT时，就使用直接插入法
	{
		InsertSort(a, high - low + 1); //当high-low小于等于常数时用直接插入排序
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
	int n = 100;  //测试样本量：随机的100个数，可以自己指定

	a = (int*)malloc(sizeof(int) * n);
	GetRandomArray(a, n);
	ShowArray(a, n);
	QuickSort(a, 0, n - 1);
	ShowArray(a, n);
	return 0;
}
