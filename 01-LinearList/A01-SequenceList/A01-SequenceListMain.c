#include "SequenceListHead.h"
/*如何看工程：
	setp1：从main函数入手，了解function；然后从头，看到无法明白的就看向头文件；
	setp2：从头文件，中的函数声明和main函数逐一了解；*/
int main()
{
	printf("\n――――――――顺序表――――――――\n\n");
	SequenceList list;
	while (1)
	{
		printf("\n选择你要做的事：\n");
		printf("0:置空顺序表\t\t1：随机初始化顺序表\t\t2:手动初始化顺序表\n");
		printf("3:显示顺序表\t\t4：追加顺序表数据\t\t5:判断顺序表是否为空\n");
		printf("6:删除顺序表的元素\t7：在顺序表中查找元素");
		int event;
		scanf("%d", &event);
		if (event == 0)
		{
			if (GoToZero(&list) == 1)
			{
				printf("Successfully.\n");
			}
			else printf("failure.\n");
		}
		else if (event == 1)
		{
			if (RandInit(&list) == 1)
			{
				printf("Successfully.\n");
			}
			else printf("failure.\n");
		}
		else if (event == 2)
		{
			PutInit(&list);
		}
		else if (event == 3)
		{
			display(&list);
		}
		else if (event == 4)
		{
			printf("输入你要追加的数据：");
			int num;
			scanf("%d", &num);
			if (append(&list,num) == 1)
			{
				printf("Successfully.\n");
			}
			else printf("failure.\n");
		}
		else if (event == 5)
		{
			if (JudgeEmpty(&list) == 1)
			{
				printf("顺序表不为空。\n");
			}
			else
				printf("顺序表为空。\n");
		}
		else if (event == 6)
		{
			int x; printf("输入数据的所在位置：");
			scanf("%d", &x);
			if (Delete(&list, x) == 1)
			{
				printf("Successfully.\n");
			}
			else printf("Failure.\n");
		}
		else if (event == 7)
		{
			int n;
			printf("输入你要查找的数据：");
			scanf("%d", &n);
			if (FindNumber(&list, n) != 0)
			{
				printf("查找成功！该数在第%d位。\n",FindNumber(&list,n)+1);
			}
			else printf("查找失败！没有该数据。\n");
		}
	}
}