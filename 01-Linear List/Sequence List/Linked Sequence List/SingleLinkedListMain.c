#include"SingleLinkedListHead.h"
/*仅适用于正数的链表；*/
int main()
{
	linklist head=NULL;  //定义一个结构体指针，名字叫做head；
	printf("――――――――――不带头结点的单链表――――――――――\n\n");

	while (1)
	{
		printf("\n选择你要做的事：\n0:初始化单链表；\t1:判断单链表是否为空；\t2:置空单链表；\n");
		printf("3:显示；   4:增;   5:找；   6:改；   7:删；   8:删除单链表；\n");
		int event;
		scanf("%d", &event);
		if (event==0)
		{
			head = Init();
		}
		else if (event == 1)
		{
			if (IsEmpty(head) == 0) printf("单链表确实为空。\n");
			else printf("单链表不为空。\n");
		}
		else if (event == 2)
		{
			if (MakeEmpty(head) == 0)  printf("置空成功。\n");
			else printf("置空失败.\n");
		}
		else if (event == 3)
		{
			Dispaly(head);
		}
		else if (event == 4)
		{
			printf("你想要什么增法：\t1:append；   2:排序式；   3:指定式；\n");
			int num, x;
			scanf("%d", &num);
			if (num == 1)
			{
				printf("\n输入你要追加的数据：");
				scanf("%d", &x);
				append(head, x);
			}
			else if (num == 2)
			{
				printf("\n输入你要排序式增加的数据：");
				scanf("%d", &x);
				InsertSort(head, x);
			}
			else if (num == 3)
			{
				int n;
				printf("输入增加数据所在的位置： ");
				scanf("%d", &n);
				printf("\n输入你要指定式增加的数据：");
				scanf("%d", &x);
				oppoint(head, x, n);

			}
			else
			{
				printf("不要乱输。\n");
			}
		}
		else if (event == 5) //找；
		{
			linklist t = NULL;
			int x;
			printf("输入你要找的数据： ");
			scanf("%d", &x);
			t = find(head, x);
			if (t == NULL)
			{
				printf("没找到！\n");
			}
			else
				printf("找到了：%d", t->data);
		}
		else if (event == 6)  //改
		{
			int x,new;
			printf("输入你要修改的数据： ");
			scanf("%d", &x);
			printf("输入新的数据： ");
			scanf("%d", &new);
			alter(head, x,new);
		}
		else if (event == 7) //删单个；
		{
			int x;
			printf("输入你要删除的数据： ");
			scanf("%d", &x);
			delete(head, x);
		}
		else if (event == 8)  //destroy;
		{
			destroy(head);
		}
		else
		{
			printf("Error!\n");
		}
	}
}
