#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* next;
}ListNode, * LinkList;

/*
 * 函数功能：头插法创建一个链表
 * Algorithm Core：
 *	 每次插入的新节点都在开头处
 */
LinkList Create_HeadInsert()
{
	LinkList s;
	LinkList L;
	int x;
	L = (LinkList)malloc(sizeof(ListNode)); //创建头结点，如果不想要头结点，则删除这两行代码
	L->next = NULL;
	scanf("%d", &x);
	while (x != 99)
	{
		s = (LinkList)malloc(sizeof(ListNode));
		s->data = x;
		s->next = L->next; //s->next指向L的后面一个元素，L->next代表着L的后面一个；
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}
void show(LinkList L)
{
	LinkList p = L->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void test01()
{
	LinkList L;
	L = Create_HeadInsert();
	show(L);
}
int main()
{
	test01();
	return 0;
}
