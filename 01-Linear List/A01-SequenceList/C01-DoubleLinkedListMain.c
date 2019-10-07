#include "DoubleLinkedListHead.h"
int main()
{
	system("color a && title 双链表");
	printf("――――――――――――双链表――――――――――\n\n");
	dlinklist head=NULL;
	head=Init();
	Display(head);

	while (1)
	{
		printf("\n选择你要做的事情：\n");
		printf("1：正向显示双链表；  2：反向显示双链表；  3：查找某个值；  4：插入某个数；  5：删除某个数\n");
		//printf("\n");
		int event;
		scanf("%d", &event);
		if (event == 1)
		{
			Display(head);
		}
		else if (event == 2)
		{
			ReverseDisplay(head);
		}
		else if (event == 3)
		{
			int num;
			printf("输入你要查找的数：");
			scanf("%d", &num);
			Find(head,num);
		}
		else if (event == 4)
		{
			int num,position;
			printf("输入你要插入的数：");
			scanf("%d", &num);
			printf("输入你要插入的位置：");
			scanf("%d", &position);
			Insert(head, num,position);
		}
		else if (event == 5)
		{
			int num;
			printf("输入你要删除的数：");
			scanf("%d", &num);
			DeleteNumber(head, num);
		}
	
	}
	system("pause");
	return 0;
}