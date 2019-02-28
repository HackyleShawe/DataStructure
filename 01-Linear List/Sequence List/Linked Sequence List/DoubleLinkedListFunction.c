#include "DoubleLinkedListHead.h"

dlinklist Init()
{/*algorithm:
		先分配第一个data的内存，并存入结构体中； while（x！=0）时，继续按照尾插法分配，在scanf后紧跟if(x==0)break来
		提前终止x为0还在分配内存；*/
	dlinklist head,assist,move;
	printf("输入各个节点的值（以0结束）：  ");
	int x;
	scanf("%d", &x);
	head = (dlinklist)malloc(sizeof(node));
	head->data = x;
	head->pre = NULL;
	head->next = NULL;
	move = head;  //把移动指针搞到head的位置；
	while (x != 0)
	{
		scanf("%d", &x);
		if (x == 0) break;
		assist = (dlinklist)malloc(sizeof(node));
		assist->data = x;
		assist->next = NULL;
		assist->pre = move;
		move->next = assist;
		move=move->next;
	}
	return head;
}

void Display(dlinklist head)
{
	dlinklist move;
	if (!head) printf("双链表是空的！\n");
	else
	{
		move = head;
		printf("此时双链表的情况是：(head<-->tail)  ");
		while (move)
		{
			printf("%d", move->data);
			if (move->next!=NULL) printf("<==>");
			move = move->next;
		}
		putchar('\n');
	}
}
void ReverseDisplay(dlinklist head)
{//function：反向显示双链表；
	dlinklist assist, move;
	move = head;
	if (!head) printf("双链表是空的！\n");
	else
	{
		while (move->next!=NULL) //跑到尾巴上去；
		{
			move = move->next;
		}
		assist = move;
		while (assist)
		{
			printf("此时双链表的情况是：(tail<-->head)  ");
			while (assist)
			{
				printf("%d", assist->data);
				if (assist->pre != NULL) printf("<==>");
				assist = assist->pre;
			}
			putchar('\n');
		}
	}
}
void Find(dlinklist head, int x)
{
	dlinklist move;
	int postion = 1;
	if (!head) printf("双链表是空的！没法找！\n");
	else
	{
		move = head;
		while (move && move->data != x)
		{
			move = move->next;
			postion += 1;
		}
		if (move)
		{
			printf("找到了，在第%d的位。\n", postion);
		}
		else
		{
			printf("没找到！\n");
		}
	}
}
void Insert(dlinklist head, int num,int position)
{//functin:插入某个数据；
	dlinklist move,assist;
	dlinklist temp;
	int check = 0;
	int counter = 2;
	if (!head)
	{
		printf("双链表是空的！没法找！\n");
		return;
	}
	if (position <= 0)
	{
		printf("位置不存在.\n");
		return;
	}
	assist = (dlinklist)malloc(sizeof(node));
	assist->data = num;
	if (position == 1)//插入位置在最首；
	{
		assist->next = head;
		assist->pre = NULL;
		head = assist;
	}
	else
	{
		move = head;
		while (counter<position) //抵达插入处；
		{
			move = move->next;
			counter += 1;
		}
		check = move->data;
		temp = move->next;
		assist->next = temp;
		move->next = assist;
		assist->pre = move;
	}
	if (check != num)
	{
		printf("插入成功。\n");
	}
	else printf("插入失败。\n");
}
void DeleteNumber(dlinklist head, int num)
{//function:删除一个数
	dlinklist move;
	dlinklist front, back;
	int check = 0;
	if (!head)
	{
		printf("双链表是空的！没法！\n");
		return;
	}
	move = head;
	front = move;
	check = move->data;
	while (move->data != num)
	{
		front = move;
		check = move->data;
		move = move->next;
	}
	back = move->next;
	front->next = back;
	back->pre = front;
	if (check != num)
	{
		printf("删除成功。\n");
	}
	else printf("删除失败。\n");
}