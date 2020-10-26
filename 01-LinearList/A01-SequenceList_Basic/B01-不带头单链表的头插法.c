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
 * 函数功能：
 * 	 不带头结点的头插法
 * Algorithm Core：
 * 	 每次插入的新节点都在开头处
 */
LinkList Create_Tail_Insert()
{
	LinkList L = NULL;
	ListNode* s;
	int x;
	scanf("%d", &x);
	while (x != 999)
	{
		s = (ListNode*)malloc(sizeof(ListNode));
		s->data = x;
		s->next = L;
		L = s;
		scanf("%d", &x);
	}
	return L;
}
void show(LinkList L)
{
	//LinkList p = L->next;
	LinkList p = L;
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
	L = Create_Tail_Insert();
	show(L);
}
int main()
{
	test01();
	return 0;
}
