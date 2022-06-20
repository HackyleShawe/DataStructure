//按大小划分为两个部分

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void exchange(int* a, int len, int num)
{
	int i; //遍历使用的下标
	int x; //[0,x]区域内的所有数都小于等于num
	int t; //交换两个数时使用的临时变量

	x = 0;//x = -1; //初始时小于等于num的区域不存在
	for (i = 0; i < len; i++)
	{
		if (a[i] < num)
		{
			t = a[i]; a[i] = a[x]; a[x] = t;
			x += 1; //属于小于等于num的区域扩大
		}
	}
}
void test01()
{
	int len = 5;
	int num = 5;
	int i;

	scanf("%d", &len);
	int* a = (int*)malloc(sizeof(int) * len);
	for (i = 0; i < len; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &num);

	exchange(a, len, num);
	for (i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
}
int main()
{
	test01();
	return 0;
}
