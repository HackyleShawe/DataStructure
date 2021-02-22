#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct Se{
	int data[MAX_SIZE];
	int len;
}Sequence;

/*
 * 函数功能：删除无序表元素值在某区间的元素
 * 输入：线性表sequence，要删除的元素值区间
 * 输出：由于要修改线性表中的元素，所以需要引用式传递参数
 * 算法：从头开始且相邻的双下标思想
 *  1.设定i遍历数组，k为符合条件个数；
 *  2.当元素不等于指定值时，将下标i的值赋值给下标i后移k个元素后的位置；
 */
void DeleteElement(Sequence *sequence, int a, int b)
{
	int k = 0;
	for (int i = 0; i < sequence->len; i++)
	{
		if (sequence->data[i] >= a && sequence->data[i] <= b)
		{
			k++;
		}
		else
		{
			sequence->data[i - k] = sequence->data[i];
		}
	}
	sequence->len -= k;
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
		sequence.data[i] = rand() % 50;
	}
	PrintArray(sequence);
	DeleteElement(&sequence, 20, 40);
	PrintArray(sequence);
	return 0;
}
