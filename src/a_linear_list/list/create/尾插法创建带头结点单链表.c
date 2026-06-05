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
Algorithm Core：
	每次插入的新节点都在结尾处
*/
LinkList Create_Tail_Insert()
{
	LinkList L;
	LinkList s, r;
	int x;
	L = (LinkList)malloc(sizeof(ListNode)); //创建头结点，如果不想要头结点，则删除这两行代码
	L->next = NULL;

	r = L; //r指向头指针
	scanf("%d", &x);
	while (x != 99)
	{
		s = (LinkList)malloc(sizeof(ListNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
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
	L = Create_Tail_Insert();
	show(L);
}
int main()
{
	test01();
	return 0;
}
