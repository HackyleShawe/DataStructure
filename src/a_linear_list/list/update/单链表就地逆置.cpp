#include <iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node* next;
}ListNode;

/*
 * 函数功能：就地逆置单链表
 * 输入：单链表
 * 输出：完成逆置后的单链表
 * 算法：将原链表的元素逐个取下，进行头插法插入到新链表中
 */
ListNode* Reverse(ListNode* list)
{
	ListNode* head = NULL; //保存就地逆置的链表
	ListNode* t = NULL; //中间变量
	while (list!= NULL)
	{
		t = list;
		list = list->next;
		t->next = head;
		head = t;
	}
	return head;
}

ListNode* CreateList() //不带头结点，尾插法
{
	ListNode* head = NULL;
	ListNode* new_node = NULL;
	ListNode* move = NULL;
	int t;
	scanf("%d", &t);

	while (t != 99)
	{
		new_node = new ListNode;
		new_node->data = t;
		new_node->next = NULL;
		if (head == NULL)
		{
			head = new_node;
			move = head;
		}
		else
		{
			move->next = new_node;
			move = move->next;
		}
		scanf("%d", &t);
	}
	return head;
}
void ShowList(ListNode* list)
{
	ListNode* cur = list; //遍历时跳过头结点
	while (cur != NULL)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}
int main()
{
	ListNode* list = CreateList();
	ShowList(list);
	list = Reverse(list);
	ShowList(list);
	return 0;
}

