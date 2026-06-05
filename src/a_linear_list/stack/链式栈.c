#define _CRT_SECURE_NO_WARNINGS  //宏
#include<stdio.h>
#include<stdlib.h>

typedef struct ChainStack
{//就是另类的单链表；指针由栈顶向栈底指去；
	int data;
	struct ChainStack *next;
}node;  
typedef node * stack;

stack init()
{
	return NULL;
}
stack push(stack top, int x) //push时的本质是头插法，head的位置是top指针；
{
	stack temp;
	temp = (stack)malloc(sizeof(node));
	temp->data = x;
	temp->next = top;
	top = temp;
	return top;//返回的是进栈后的栈顶指针；
}
stack pop(stack top)
{
	stack temp;
	if (!top)
	{
		printf("链式栈是空的，没法出栈！\n"); return NULL;
	}
	temp = top; //搞到辅助指针哪里；
	top = top->next;//向下移动辅助指针；
	free(temp);
	return top;
}
void display(stack top)
{
	if (!top)
	{
		printf("链式栈是空的，没法display！\n"); 
	}
	else
	{
		stack move;
		move = top;
		printf("此时栈全局为： ");
		while (move)
		{
			printf("%3d", move->data);
			move = move->next;
		}
		
	}

}
void read(stack top)
{
	if (!top)
	{
		printf("链式栈是空的，没法read！\n");
	}
	else
	{
		printf("此时的栈顶元素是：%d\n", top->data);
	}
}
int main()
{
	stack top;
	top = init();
	if (top == NULL) printf("初始化成功！\n");
	else printf("初始化失败！\n");
	int i;
	for (i = 0; i < 11; i++)
	{
		top = push(top, i);
	}
	printf("\n进栈了%d个元素后,", i);
	read(top);
	display(top);
	
	for (i = 0; i < 3; i++)
	{
		top = pop(top);
	}
	printf("\n出栈了%d个元素后,", i);
	read(top);
	system("pause");
	return 0;
}