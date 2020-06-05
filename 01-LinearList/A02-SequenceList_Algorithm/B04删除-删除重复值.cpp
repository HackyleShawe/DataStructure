/*===============================起始 分割线================================
题目：
	从有序順序表中删除所有其值重复的元素，使表中所有元素的值均不同．
算法思想：
	注意是有序顺序表，值相同的元素一定在连续的位置上，用类似于直接插入排序的思想，初始时将第一个元素视为非重复的有序表。
	第二个元素之后，依次判断后面的元素是否与前面非重复有序表的最后一个元素相同，
	若相同则继续向后判断，若不同则插入到前面的非重复有序表的最后，直至判断到表尾为止。

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
bool DeleteRepeat(SqList& L)
{
	if (L.lenght == 0)
	{
		return false;
	}
	int i, j;
	for (i = 0, j = 1; j < L.lenght; j++)
	{
		if (L.data[i] != L.data[j])
		{
			L.data[++i] = L.data[j];
		}
	}
	L.lenght = i + 1;
	return true;
}
void test01()
{
	SqList L;
	scanf("%d", &L.lenght);
	for (int i = 0; i < L.lenght; i++)
	{
		scanf("%d", &L.data[i]);
	}
	if (DeleteRepeat(L))
	{
		cout << "Done!" << endl;
		for (int i = 0; i < L.lenght; i++)
		{
			cout << L.data[i] << " ";
		}
	}
	else
	{
		cout << "Error hapended!" << endl;
	}
}
int main()
{
	test01();
	return 0;
}

/*===============================结束 分割线================================*/