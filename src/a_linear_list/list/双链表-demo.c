#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef struct node
{
	int data;
	struct node* pre;
	struct node* next;
}Node; //struct node 完全等于 Node（结构体变量）
typedef Node* LinkList; //struct node * 完全等于 LinkList（结构体指针）

int main()
{
	LinkList head = (LinkList)malloc(sizeof(Node));
	assert(head != NULL);  //检查malloc之后是不是空间不够，返回了空指针NULL（WarningC6011：取消对NULL指针的引用）
	LinkList NodeAa = (LinkList)malloc(sizeof(Node));
	assert(NodeAa != NULL);
	LinkList NodeBb = (LinkList)malloc(sizeof(Node));
	assert(NodeBb != NULL);
	LinkList NodeCc = (LinkList)malloc(sizeof(Node));
	assert(NodeCc != NULL);

	head->data = 101;
	head->pre = NULL;
	head->next = NodeAa;

	NodeAa->data = 202;
	NodeAa->pre = head;
	NodeAa->next = NodeBb;

	NodeBb->data = 303;
	NodeBb->pre = NodeAa;
	NodeBb->next = NodeCc;

	NodeCc->data = 404;
	NodeCc->pre = NodeBb;
	NodeCc->next = NULL;  //单链表中：NodeCc->next = NULL;

	LinkList p = head; //把链表头结点的下一个交给指针p，去遍历
	printf("顺序遍历：");
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}

	printf("\n逆序遍历：");
	LinkList tail = NodeCc;
	p = tail;
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->pre;
	}

	return 0;
}
