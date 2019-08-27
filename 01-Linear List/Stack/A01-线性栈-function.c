#include"stack.h"

int MakeEmpty(SequenceStack *stack)
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

int JudgeIsEmpty(SequenceStack *stack)
{
	if (stack->top == 0)
		return 1;  //确实为空
	else return 0;
	/*使用风骚的代码：return（stack->top?1:0);*/
}

int push(SequenceStack *stack, int x)
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

int pop(SequenceStack *stack)
{
	int flag = 0;
	if (stack->top == 0)
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

void ShowStack(SequenceStack *stack)
{
	int t;
	printf("底部-->");
	for (t=0; t <stack->top; t++)
	{
		printf("%5d", stack->mystack[t]);
	}
	printf("\n");
}