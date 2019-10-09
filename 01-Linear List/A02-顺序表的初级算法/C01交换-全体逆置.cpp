题目：将顺序表L的所有元素逆置，要求时间复杂度为O(1);

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX_SIZE 100
using namespace std;

typedef int ElemType;
typedef struct {
	ElemType data[MAX_SIZE];
	int length;
}SqList;

/*
算法思想：
	遍历前半部分，把a[i++]与a[n-i-1]交换；
*/
void reverse(SqList& L)
{
	int i, n;
	ElemType t;
	for (i = 0, n = L.length / 2; i < n; i++)
	{
		t = L.data[i];
		L.data[i] = L.data[L.length - i - 1];
		L.data[L.length - i - 1] = t;
	}
}
void ShowSqList(SqList L)
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		cout << L.data[i] << "  ";
	}
	cout << endl;
}
void test01()
{
	SqList L;
	int i;
	scanf("%d", &L.length);
	for (i = 0; i < L.length; i++)
	{
		scanf("%d", &L.data[i]);
	}
	ShowSqList(L);
	reverse(L);
	ShowSqList(L);
}
int main()
{
	test01();
	return 0;
}
/*===============================结束 分割线================================*/



/*===============================起始 分割线================================*/
/*
算法思想：双指针思想
	设置双指针，一个从前往后，一个从后往前，相互交换，直至两指针碰面为止
*/
void DoublePointerReverse(SqList &L)
{
	int i, j, t;
	i = 0; //头
	j = L.length - 1; //尾
	while (i < j)
	{
		t = L.data[i];
		L.data[i] = L.data[j];
		L.data[j] = t;
		i += 1;
		j -= 1;
	}
}

/*===============================结束 分割线================================*/