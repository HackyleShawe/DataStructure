//所谓的有序表查找，就是从已经排好序了的查找表中查找关键字


/*===============================起始 分割线================================*/
/*
程序目的：
	在有序表中实现二分查找法
程序功能：
	动态随机数组、冒泡排序构造有序表、二分查找法
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int BinarySearch(int *a, int n,int x)
{
	int low, high, mid;
	low = 0, high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (x == a[mid])
		{
			return mid;
		}
		else if (x > a[mid])
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}
void BubbleSort(int *a, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				a[j] = a[j] ^ a[j + 1];
				a[j + 1] = a[j] ^ a[j + 1];
				a[j] = a[j] ^ a[j + 1];
			}
		}
	}
}
void test01()
{
	int *a;
	int n, i;
	int x,result;
	srand((unsigned int)time(NULL));
	n = rand() % 11 + 5; //[5,15]
	a = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 101; //[0,100]
		printf("%d  ", a[i]);
	}
	BubbleSort(a, n);
	printf("\n你想查找谁: ");
	scanf("%d", &x);
	result=BinarySearch(a, n,x);
	if (-1 != result)
	{
		printf("\n在第%d位\n", result + 1);
	}
	else printf("\n没找到!\n");
	putchar('\n');
}
int main()
{
	test01();
	system("pause");
	return 0;
}

/*===============================结束 分割线================================*/




/*===============================起始 分割线================================*/
/*
程序目的：
	递归实现二分查找法
程序功能：
	动态随机数组、STL排序算法、递归二分查找法
注意：
	C++实现，使用了STL
*/
#include <iostream>
#include <ctime>
#include <algorithm>
#define N 10
using namespace std; 
int RecursionBS(int *a, int x, int low, int high)
{
	if (low > high)
	{
		return -1;
	}
	int middle = (low + high) / 2;
	if (x == a[middle])
	{
		return middle;
	}
	else if (x > a[middle])
	{
		RecursionBS(a, x, middle + 1, high);
	}
	else
	{
		RecursionBS(a, x, low, middle - 1);
	}
}
int main()
{
	int a[N];
	int i; //循环变量
	int x; //待查找的变量
	int loc; //该数的所在位置

	srand((unsigned int)time(NULL)); //时间随机种子

	for (i = 0; i < N; i++)
	{
		a[i] = rand() % 101; //[0,100]
	}
	sort(a, a + N);
	for (i = 0; i < N; i++)
	{
		printf("%d  ", a[i]);
	}

	cout << "\n输入你要查找的数：";
	cin >> x;

	loc = RecursionBS(a, x,0,N-1);
	if (loc == -1)
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "该数在第" << loc + 1 << "位" << endl;
	}
	system("pause");
	return 0;
}

/*===============================结束 分割线================================*/