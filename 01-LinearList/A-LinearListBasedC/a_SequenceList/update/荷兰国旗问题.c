#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void NetherlandsFlag(int* a, int L, int R, int num)
{
	int less = L - 1;
	int more = R + 1;
	int cur = L;
	int t;

	while (cur < more)
	{
		if (a[cur] < num) //对应算法思想中的①操作
		{
			less++; //因为初始时less=L-1，当L=0时，less=-1；若不先加一，则a[-1]不合法！
			t = a[less]; a[less] = a[cur]; a[cur] = t;
			cur++;
		}
		else if (a[cur] > num) //对应算法思想中的③操作
		{
			more--;
			t = a[cur]; a[cur] = a[more]; a[more] = t;
		}
		else  //对应算法思想中的②操作
		{
			cur++;
		}
	}
	//最终的等于区域是：下标为[less+1, more-1]
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

	NetherlandsFlag(a, 0, len-1, num);
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
