
// 功能需求：
// 	从顺序表中删除具有最小值元素（假设唯一）并有函数返回被删元素的值。
// 	空出的位置由最后一个元素填补，若循序表为空则显示出错信息并退出运行。


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
 * 函数功能：
 * 	 删除顺序表中最小值，并通过value引用返回
 * 算法思想：
 * 	 遍历顺序表，查找最小值元素并记住其位置，搜索结束后用最后一个元素填补空出的原最小值元素的位置。
 * 函数返回：
 * 	 删除成功返回true，失败返回false
*/
bool DeleteMin(SqList &L, ElemType &value)
{
	if (L.length == 0)
	{
		return false;
	}
	value = L.data[0]; //假设最小值就是第一个元素
	int pos = 0; //记录最小值的位置，并假设第一元素就是最小值

	for (int i = 1; i < L.length; i++)
	{
		if (L.data[i] < value)
		{
			value = L.data[i];
			pos = i;
		}
	}
	L.data[pos] = L.data[L.length - 1]; //空出的位置由最后一个元素填补
	L.length -= 1;
	return true; //value就是当前顺序表中最小的值
}
void test01()
{
	SqList L;
	int i;
	int value = 0;

	scanf("%d", &L.length);
	for (i = 0; i < L.length; i++)
	{
		scanf("%d", &L.data[i]);
	}
	if (DeleteMin(L, value))
	{
		cout << "最小值为：" << value << endl;
	}
	else
	{
		cout << "出错！" << endl;
	}
}
int main()
{
	test01();
	return 0;
}
