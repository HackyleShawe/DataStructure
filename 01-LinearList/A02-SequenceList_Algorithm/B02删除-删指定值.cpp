
// 功能需求：对长度为的顺序表L，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，该算法删除线性表中所有值为x的数据元素。


/*===============================第一种算法思想================================*/
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
 * 函数功能：删除线性表中所有值为x的数据元素
 * 算法思想：从头开始且相邻的双指针
 * 	 1.用k记录顺序表中不等于x的元素个数。遍历顺序表，同时统计k，并将不等于x的元素向前移动k个位置；
 * 	 2.遍历顺序表，设置双指针k和i，其中k是保存符合条件的下标；
*/
void DeleteValue(SqList& L, ElemType x)
{
	int k=0, i;
	for (i = 0; i < L.lenght; i++)
	{
		if (L.data[i] != x)
		{
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.lenght = k;
}

void test01()
{
	SqList L;
	int i;
	int x;
	scanf("%d", &L.lenght);
	for (i = 0; i < L.lenght; i++)
	{
		scanf("%d", &L.data[i]);
	}

	scanf("%d", &x);
	DeleteValue(L, x);
	for (i = 0; i < L.lenght; i++)
	{
		printf("%d  ", L.data[i]);
	}
	printf("\n");
}
int main()
{
	test01();
	return 0;
}
/*===============================第一种算法思想================================*/




/*===============================第二种算法思想================================*/
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
算法思想：从头开始且相邻的双指针
	用k记录顺序表中等于x的个数；遍历顺序表的时统计k，同时将不等于x的元素前移k个位置。
*/
void DeleteValue(SqList& L, ElemType x)
{
	int k = 0, i = 0;
	for (i=0; i < L.lenght; i++)
	{
		if (L.data[i] == x) //有k个元素是等于x的
		{
			k++;
		}
		else
		{
			L.data[i - k] = L.data[i]; //当前元素前移k个位置
		}
	}
	L.lenght = L.lenght - k; //因为有k个元素是相同的，所以删除后总长要减去k
}

void test01()
{
	SqList L;
	int i;
	int x;
	scanf("%d", &L.lenght);
	for (i = 0; i < L.lenght; i++)
	{
		scanf("%d", &L.data[i]);
	}

	scanf("%d", &x);
	DeleteValue(L, x);
	for (i = 0; i < L.lenght; i++)
	{
		printf("%d  ", L.data[i]);
	}
	printf("\n");
}
int main()
{
	test01();
	return 0;
}
/*===============================第二种算法思想================================*/




/*===============================第三种算法思想================================*/
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
算法思想：双指针
	设置头尾指针i、j，同时向中间移动；左端值为x时，将右端的非x值移动到x所在的位置，直到两指针相遇；
	注意，这种方法会混乱顺序表原有的顺序
*/
void DeleteValue(SqList &L	, ElemType x)
{
	int i = 0, j = L.lenght - 1; //i是头指针，j是尾指针
	while (i < j)
	{
		while (L.data[i] != x)
		{
			i++;
		}
		while (L.data[j] == x)
		{
			j--;
		}

		L.data[i] = L.data[j];
		j--;
		L.lenght--;
		i++;
	}
}

void test01()
{
	SqList L;
	int i;
	int x;
	scanf("%d", &L.lenght);
	for (i = 0; i < L.lenght; i++)
	{
		scanf("%d", &L.data[i]);
	}

	scanf("%d", &x);
	DeleteValue(L, x);
	for (i = 0; i < L.lenght; i++)
	{
		printf("%d  ", L.data[i]);
	}
	printf("\n");
}
int main()
{
	test01();
	return 0;
}
/*===============================第三种算法思想================================*/

