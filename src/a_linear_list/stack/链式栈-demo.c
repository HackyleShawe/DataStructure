#include <stdio.h>
#include  <stdlib.h>
#include  <assert.h>

typedef struct node
{
	int data;
	struct node* next;
}stack;

int main()
{
	stack* top = NULL; //设置一个栈顶指针，方便出栈、取栈操作
	stack* bottom = (stack*)malloc(sizeof(stack));
	assert(bottom != NULL);
	bottom->data = 100;
	bottom->next = NULL;
	top = bottom;

	stack* NodeAa = (stack*)malloc(sizeof(stack));
	assert(NodeAa != NULL);
	NodeAa->data = 200;
	NodeAa->next = bottom; //插入到bottom节点的前面，即头插法
	top = NodeAa;

	stack* NodeBb = (stack*)malloc(sizeof(stack));
	assert(NodeBb != NULL);
	NodeBb->data = 300;
	NodeBb->next = NodeAa;
	top = NodeBb;

	printf("栈顶元素：%d\n", top->data);

	//出栈
	stack* t = top;
	top = top->next;
	free(t);
	printf("栈顶元素：%d\n", top->data);
	return 0;
}
