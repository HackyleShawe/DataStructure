#include <iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node* next;
}ListNode;

/*
 * 函数功能：删除重复元素
 * 输入：链表
 * 输出：去重后的链表(由于是引用，所以不用返回该链表)
 * 算法：从头遍历，逐个取出元素与其后的元素一一比较，有重复则删除
 */
void DeleteDuplicate(ListNode* list)
{
	ListNode* cur = list; //遍历
	ListNode* node = NULL; //遍历cur后的所有元素
	ListNode* pre_node = NULL; //指向node元素的前一个元素

	while (cur != NULL)
	{
		node = cur;
		pre_node = node;
		while (node != NULL)
		{
			if (node->data == cur->data)
			{
				pre_node->next = node->next;
			}
			pre_node = node;
			node = node->next;
		}
		cur = cur->next;
	}
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
	DeleteDuplicate(list);
	ShowList(list);
	return 0;
}
