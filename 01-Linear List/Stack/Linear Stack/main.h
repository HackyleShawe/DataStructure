#include "stack.h"


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
			if (push(&stack, x)==1) printf("进栈成功!\n");
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