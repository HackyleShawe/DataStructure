
/*===============================起始 分割线================================
题目：
	已知在一维数组A[m+n]中依次存放着两个线性表 (a1, a2, a3, …, am) 和(b1, b2, b3, …, bn)。
	试编写一个函数，将数组中两个顺序表的位置互换，即将 (b1, b2, b3, …, bn) 放在 (a1, a2, a3, ..., am) 的前面。

算法思想：
	首先将数组A[m+n]中的全部元素 (a1, a2, a3, …, am, bi, b2, b3, …, bn) 原地逆置为 (bn, bn-1, bn-2, …, b1, am, am-1, am-2, …, a1)，
	再对前n个元素和后m个元素分别使用逆置算法，就可以得到(b1, b2, b3, …, bn, a1, a2, a3, …, am)，从而实现顺序表的位置互换。

=================================结束 分割线================================*/



/*===============================起始 分割线================================*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX_SIZE 100
using namespace std;
typedef int ElemType;
typedef struct Sq
{
	ElemType data[MAX_SIZE];
	int lenght;
}SqList;

/*
算法思想：双下标思想
*/
bool MyReverse(SqList& L, int left, int right)
{
	int i, t;
	if (left > right || right > L.lenght)
	{
		return false;
	}
	int mid = (left + right) / 2;
	for (i = left; i < left + mid && i<right; i++) //更容易理解的写法
	{
		t = L.data[i]; L.data[i] = L.data[right]; L.data[right] = t;
		right--;
	}
	/*for (int i = 0; i < mid - left; i++) //等价的高级写法
	{
		L.data[left+i] = L.data[left + i] ^ L.data[right - i];
		L.data[right-i] = L.data[left + i] ^ L.data[right - i];
		L.data[left+i] = L.data[left + i] ^ L.data[right - i];
	}*/
	return true;
}

bool ReversePart(SqList &L,int n,int m)
{
	if (L.lenght<0 || n>L.lenght || m > L.lenght)
	{
		return false;
	}
	MyReverse(L, 0, n + m - 1);
	MyReverse(L, 0, n - 1);
	MyReverse(L, n + 1, n + m - 1);
	return true;
}
void test01()
{
	SqList L;
	int n, m;
	scanf("%d", &L.lenght);
	for (int i = 0; i < L.lenght; i++)
	{
		scanf("%d", &L.data[i]);
	}
	scanf("%d%d", &n, &m);
	ReversePart(L, n, m);
	for (int i = 0; i < L.lenght; i++)
	{
		cout << L.data[i] << " ";
		if (i == n)
		{
			cout << " || ";
		}
	}
}
int main()
{
	test01();
	return 0;
}

/*测试用例：
5
1 5 9 3 6
2 3
6 3 9 || 5 1
*/
/*===============================结束 分割线================================*/

