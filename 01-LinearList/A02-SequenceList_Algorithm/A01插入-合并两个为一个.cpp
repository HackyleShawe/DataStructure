//功能需求：将两个有序顺序表合并为一个有序的顺序表。

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
 * 函数功能：将两个有序顺序表合并为一个有序的顺序表
 * 算法思想：
 *   1.一个顺序表一个下标。依次比较两个顺序表的下标所在数，把符合条件的那个数下标前进，并将其复制到新的顺序表；
 *	 2.然后，看那个表还有剩余，则把剩下的部分加到新的顺序表即可。
 */
void Merge(SqList& A, SqList& B, SqList& L)
{
	int i=0, j=0, k=0;
	while (i < A.lenght && j < B.lenght) //注意，这里的条件一定是&&，而不是 ||
	{
		if (A.data[i] < B.data[j])
		{
			L.data[k++] = A.data[i++];
		}
		else
		{
			L.data[k++] = B.data[j++];
		}
	}
	while (i < A.lenght)
	{
		L.data[k++] = A.data[i++];
		i++;
	}
	while (j < B.lenght)
	{
		L.data[k++] = B.data[j++];
		j++;
	}
}
void test01()
{
	SqList A, B, L;
	scanf("%d %d", &A.lenght, &B.lenght);
	L.lenght = A.lenght + B.lenght;
	for (int i = 0; i < A.lenght; i++)
	{
		scanf("%d", &A.data[i]);
	}
	for (int i = 0; i < B.lenght; i++)
	{
		scanf("%d", &B.data[i]);
	}
	Merge(A, B, L);
	for (int i = 0; i < L.lenght; i++)
	{
		cout << L.data[i] << " ";
	}
}
int main()
{
	test01();
	return 0;
}

