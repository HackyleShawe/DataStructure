
/*==================================新的开始 分割线==============================*/
/*
程序目的：
	快速理解静态数组和动态数组
程序功能：
	打印动态数组的值
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//实现静态数组
void test01()
{
	int a[10];
	int n;
	//int b[n];  在运行前、编译时必须确定n的值
}
//实现动态数组
void test02()
{
	int *a;
	int n;
	scanf("%d",&n); //你想要数组的元素有多少个就输入多少个
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
	test();
	system("pause");
	return 0;
}

/*==================================完结 分割线==================================*/

