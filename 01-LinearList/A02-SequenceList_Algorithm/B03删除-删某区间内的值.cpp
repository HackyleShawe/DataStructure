
// 功能需求：
// 	1.从有序顺序表中删除其值在给定值s与t之间（要求下s<t）的所有元素，
// 	2.如果s或t不合理或顺序表为空，则显示出错信息并退出运行。



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
 * 函数功能：
 * 	 删除有序表中某区间的值
 * 算法思想：
 * 	 ∵ 有序表中，所删除的元素必然是相连的整体
 * 	 ∴ ①先寻找大于等于s的第一个元素(第一个删除的元素)，②再寻找大于t的第一个元素(最后一个删除的元素的下一个元素)；
 * 	   ③将这段元素删除，只需要将后面的元素前移！！！
 */
bool DeleteSection(SqList& L, ElemType s, ElemType t)
{
	int i, j;
	if (s > t || L.lenght == 0)
	{
		return false;
	}
	for (i = 0; i < L.lenght && L.data[i] < s; i++) ; //寻找大于等于s的第一个元素
	if (i >= L.lenght) //越界，表示没有根本不存在该区间
	{
		return false;
	}
	for (j = i; j<L.lenght && L.data[j]<=t; j++) ; //寻找大于t的第一个元素
	for (; j < L.lenght; j++) //前移
	{
		L.data[i++] = L.data[j];
	}
	L.lenght = i;
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
	int s, t;
	scanf("%d%d", &s, &t);
	if (DeleteSection(L, s, t))
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





// 功能需求：从順序表中删除其值在给定值s与t之间（包含s和t，要求s<t）的所有元素，
// 		如果s或t不合理或顺序表为空，则显示出错信息并退出运行。


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
 * 函数功能：
 * 	 删除顺序表中某区间的值
 * 算法思想：
 * 	 遍历，用k记录下元素值在s到t之间元素的个数。
 * 	 对于当前扫描的元素，若其值不在s到t之间，则k前移k个位置；否则执行k++。
 * 	 由于这样每个不在s到t之间的元素仅移动一次，所以算法效率高。
*/
bool DeleteSection(SqList& L, ElemType s, ElemType t)
{
	int i;
	int k = 0;
	if (L.lenght == 0 || s > t)
	{
		return false;
	}
	for (i = 0; i < L.lenght; i++)
	{
		if (L.data[i] >= s && L.data[i] <= t)
		{
			k++;
		}
		else
		{
			L.data[i - k] = L.data[i]; //当前元素向前移动k位
		}
	}
	L.lenght -= k;
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
	int s, t;
	scanf("%d%d", &s, &t);
	if (DeleteSection(L, s, t))
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