#include <stdio.h>
#define MAX 100

typedef struct
{
	int data[MAX];
	int top;
}stack;

int main()
{
	stack MyStack;

	//初始化栈
	MyStack.data[MAX] = 0;
	MyStack.top = -1;

	//进栈操作
	MyStack.data[++MyStack.top] = 100;  //栈顶指针往上移
	MyStack.data[++MyStack.top] = 200;

	//取数据
	printf("栈顶元素为：%d\n", MyStack.data[MyStack.top]);

	//出栈操作
	MyStack.top--;
	printf("栈顶元素为：%d\n", MyStack.data[MyStack.top]);

	return 0;
}
