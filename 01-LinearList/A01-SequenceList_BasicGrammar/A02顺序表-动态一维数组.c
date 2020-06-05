#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void static_array()
{
	int a[10];
	int n;
	//int b[n];  在运行前、编译时必须确定n的值
}

/*
函数功能：
	实现动态数组
算法思想：
	malloc运行时动态分配内存
*/
void dynamic_array()
{
	int* a;
	int n;
	scanf("%d", &n); //你想要数组的元素有多少个就输入多少个
	a = (int*)malloc(n * sizeof(int)); //分配容量为5的int型的空间

	for (int i = 0; i < n; i++)
	{
		a[i] = i + 10;
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

int main()
{
	dynamic_array();
	system("pause");
	return 0;
}
