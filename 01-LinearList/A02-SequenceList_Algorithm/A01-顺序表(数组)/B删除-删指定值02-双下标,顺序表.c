#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct Se{
	int data[MAX_SIZE];
	int len;
}Sequence;

/*
 * 函数功能：删除线性表中的所有X元素
 * 输入：线性表sequence，要删除的元素x
 * 输出：由于要修改线性表中的元素，所以需要引用式传递参数
 * 算法：从头开始且相邻的双下标思想
 *  1.设定i遍历数组，k为符合条件的数组下标；
 *  2.当元素不等于指定值时，将下标i的值赋值给下标k；
 */
void DeleteElement(Sequence *sequence, int x)
{
	int k = 0;
	for (int i = 0; i < sequence->len; i++)
	{
		if (sequence->data[i] != x)
		{
			sequence->data[k++] = sequence->data[i];
		}
	}
	sequence->len = k;
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
		sequence.data[i] = i * 5;
	}
	PrintArray(sequence);
	DeleteElement(&sequence, 20);
	PrintArray(sequence);
	return 0;
}

