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
 * 目标功能：尾插法
 * Algorithm Core：
 *   每次插入的新节点都在结尾处
 */
LinkList Create_Tail_Insert()
{
	LinkList L = NULL;
	LinkList s, r = NULL;
	int x;

	scanf("%d", &x);
	while (x != 99)
	{
		s = (ListNode*)malloc(sizeof(ListNode));
		s->data = x;
		if (L == NULL) //对第一个节点的处理
		{
			L = s;
		}
		else //非第一个节点的处理
		{
			r->next = s;
		}
		r = s;
		scanf("%d", &x);
	}
	if (r != NULL)
	{
		r->next = NULL;
	}
	return L;
}

void show(LinkList L)
{
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
