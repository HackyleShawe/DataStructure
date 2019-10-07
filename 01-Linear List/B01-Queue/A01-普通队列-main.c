#include"queue.h"
int main()
{/*algorihtm:
			用一个数组来保存数据，用fornt来保存队列的头部的【即数组的下标】，用rear来保存队列的尾部；
			入队列是rear++；出队列时front++；*/
	printf("――――――――――――实现线性队列――――――――――――");
	queue sq; //sequence queue:线性队列；
	sq=init();
	if (sq->front == 0 && sq->rear == 0) printf("\n初始化成功！\n");
	else printf("\n初始化失败！\n");

	while (1)
	{
		printf("\n选择你要做的事情：1:判断队列是否为空；   2：置空队列；   3：显示队列；\n");
		printf("4:入队列；   5：出队列；   6：查找队列中的某个元素；\n");
		int event;
		scanf("%d", &event);
		if (event == 1)
		{
			IsEmpty(sq);
		}
		else if (event == 2)
		{
			MakeEmpty(sq);
		}
		else if (event == 3)
		{
			display(sq);
		}
		else if (event == 4)
		{
			int i;
			for (i = 1; i < 11;i++)
			ComeIn(sq, i);
		}
		else if (event == 5)
		{
			int j = 0;
			for (; j < 3;j++)
			out(sq);
		}
		else if (event == 6)
		{
			int x;
			printf("PUT IN YOU WILL BE FIND THE NUMBER: ");
			scanf("%d", &x);
			find(sq, x);
		}
		else
		{
			printf("输入错误！重新输入！\n");
		}
	}


}