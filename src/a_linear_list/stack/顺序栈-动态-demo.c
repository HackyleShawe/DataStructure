#include <stdio.h>
#include  <stdlib.h>
#include  <assert.h>

typedef struct
{
	int* data;
	int top;
}stack;

int main()
{
	int size = 5;
	stack* MyStack = (stack*)malloc(sizeof(stack)); //为结构体分配内存
	assert(MyStack);

	//初始化
	MyStack->data = (int*)malloc(sizeof(int) * size); //为动态线性栈分配内存
	assert(MyStack->data != NULL);
	MyStack->top = -1;

	//压栈
	MyStack->data[++MyStack->top] = 100;
	MyStack->data[++MyStack->top] = 200;
	MyStack->data[++MyStack->top] = 300;

	//出栈
	MyStack->top--;
	printf("栈顶元素为：%d\n", MyStack->data[MyStack->top]);

	//重新分配大小
	size *= 2;
	MyStack->data = (int*)realloc(MyStack->data, size); //重新分配内存
	assert(MyStack->data != NULL); //注意，这将可能会导致原始的MyStack->data块内存泄露；这里仅作为演示，实际开发时慎用！

	MyStack->data[++MyStack->top] = 400;
	printf("栈顶元素为：%d\n", MyStack->data[MyStack->top]);
	return 0;
}
