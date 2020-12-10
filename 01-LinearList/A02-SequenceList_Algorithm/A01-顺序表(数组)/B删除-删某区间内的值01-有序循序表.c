#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct Se{
	int data[MAX_SIZE];
	int len;
}Sequence;

/*
 * 函数功能：删除有序表元素值在某区间的元素
 * 输入：线性表sequence，要删除的元素值区间[a,b]
 * 输出：由于要修改线性表中的元素，所以需要引用式传递参数
 * 算法：
 *  1.由于是有序，向右找第一个大于a的，记为left; 向左找第一个小于b的,记为right;
 *  2.将这段元素删除，只需要将后面的元素前移
 */
void DeleteElement(Sequence *sequence, int a, int b)
{
	int left = 0, right = sequence->len - 1;

	//向右找第一个大于a的
	while (sequence->data[left] < a)
	{
		left++;
	}
	
	//向左找第一个小于b的
	while (sequence->data[right] > b)
	{
		right--;
	}
	right++; //right如果不前移一位，会出现临界值问题

	while (right < sequence->len)
	{
		sequence->data[left++] = sequence->data[right++];
	}

	sequence->len = left;
}
void PrintArray(Sequence sequence)
{
	for (int i = 0; i < sequence.len; i++)
	{
		printf("%5d", sequence.data[i]);
	}
	printf("\n");
}
int main()
{
	Sequence sequence;
	sequence.len = 10;
	for (int i = 0; i < sequence.len; i++)
	{
		sequence.data[i] = i*5;
	}
	PrintArray(sequence);
	DeleteElement(&sequence, 20, 40);
	PrintArray(sequence);
	return 0;
}

