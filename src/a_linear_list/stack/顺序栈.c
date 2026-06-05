#define _CRT_SECURE_NO_WARNINGS  //宏
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#define MAX 100
/*Stack:栈，LIFO：后进先出表；*/
typedef struct mystack
{
	int mystack[MAX];  //栈的容量，其实就是一个竖起来的特殊数组！
	int top;  //用于指向栈顶，从而判断栈的状态；
}SequenceStack;


int MakeEmpty(SequenceStack* stack)
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		stack->mystack[i] = 0;
	}
	stack->top = 0;
	if (stack->top == 0 && stack->mystack[0] == 0)
	{
		return 1;  //置空成功；
	}
	else return 0;
}

int JudgeIsEmpty(SequenceStack* stack)
{
	if (stack->top == 0)
		return 1;  //确实为空
	else return 0;
	/*使用风骚的代码：return（stack->top?1:0);*/
}

int push(SequenceStack* stack, int x)
{
	int flag = 0;
	if (stack->top == MAX)
	{
		printf("栈已经是满的了，没办法进去了。\n");
		exit(0);
	}
	else
	{
		stack->mystack[stack->top++] = x;
		flag = stack->top;
	}
	if (flag != 0) return 1;  //入栈成功；
	else return 0;
}

int pop(SequenceStack* stack)
{
	int flag = 0;
	if (stack->top == 0) //这里不严谨，应该是"if(stack->top < 0)"
	{
		printf("栈已经没有任何东西了，没办法再POP了。\n");
		exit(0);
	}
	else
	{
		flag = stack->top;
		stack->top -= 1;
	}
	if (flag > stack->top)  return 1;  //POP成功；
	else return 0;
}

void ShowStack(SequenceStack* stack)
{
	int t;
	printf("底部-->");
	for (t = 0; t < stack->top; t++)
	{
		printf("%5d", stack->mystack[t]);
	}
	printf("\n");
}



int main()
{
	printf("――――――――――顺序栈――――――――――\n");
	SequenceStack stack;

	while (1)
	{
		printf("\n\n选择你要实现的功能：\n");
		printf("\n1:置空栈；\t2:判断栈是否为空；\t3:进栈；\t4:出栈；\t5:显示栈；\n");
		int event = 0;

		scanf("%d", &event);
		if (event == 1)
		{
			if (MakeEmpty(&stack) == 1) printf("置空成功！\n");
			else printf("置空失败！\n");
		}
		else if (event == 2)
		{
			if (JudgeIsEmpty(&stack) == 1) printf("栈是空的！\n");
			else  printf("栈不是空的！\n");
		}
		else if (event == 3)
		{
			int x;
			printf("输入进栈的数据：");
			scanf("%d", &x);
			if (push(&stack, x) == 1) printf("进栈成功!\n");
			else printf("进栈失败!\n");
		}
		else if (event == 4)
		{
			if (pop(&stack) == 1) printf("出栈成功!\n");
			else printf("出栈失败！\n");
		}
		else if (event == 5)
		{
			printf("此时的栈情况是：\t");
			ShowStack(&stack);
		}
		else
		{
			printf("不要乱输！\n");
		}
	}


	return 0;
}