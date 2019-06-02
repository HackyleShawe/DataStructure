#include"link_queue.h"
int main()
{
	printf("――――――――――――链式队列的实现――――――――――――\n");
	queue qu;  //区分queue *qu;和queue qu;    
				/*queue qu;是向内存申请一片内存； queue *qu;是定义一个queue类型的指针；*/
	init(&qu);
	 
	while (1)
	{
		printf("\n选择你要做的事：\n");
		printf("1:置空队列；  2：判断是否为空；  3：显示队列；  4:进入；\n");
		printf("5:出队列（删）；   6：查找；\n");
		int event;
		scanf("%d", &event);
		if (event == 1)
		{
			MakeEmpty(&qu);
		}
		else if (event == 2)
		{
			IsEmpty(&qu);
		}
		else if (event == 3)
		{
			display(&qu);
		}
		else if (event == 4)
		{
			/*int x;
			printf("输入你要进入的数据：");
			scanf("%d", &x);*/
			int i;
			for (i = 1; i <= 5;i++)
			input(&qu, i);
		}
		else if (event == 5)
		{
			OutQueue(&qu);
		}
		else if (event == 6)
		{
			int x;
			printf("输入你要查找的数据：");
			scanf("%d", &x);
			find(&qu, x);
		}
		else
		{
			printf("输出错误，本次输入无效！\n");
		}
	}
	system("pause");
}