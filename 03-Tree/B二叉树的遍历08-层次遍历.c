//非递归实现层次遍历
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
using namespace std;

typedef struct node
{
	struct node* lchild;
	struct node* rchild;
	char data;
}node;

node* CreateBinTree() //前序、递归方式来创建一颗二叉树
{
	node* p; //节点指针；
	char ch;
	if ((ch = getchar()) == '#')
	{
		p = NULL;
	}
	else
	{
		p = new(node);
		p->data = ch;
		p->lchild = CreateBinTree(); //创建左子树，记作L
		p->rchild = CreateBinTree();//创建右子树，记作R
	}
	return p;
}

void LevelOrder(node* root)
{
	if (root == NULL)
	{
		return;
	}
	deque<node*> tree_node_queue;
	tree_node_queue.push_back(root);

	while (!tree_node_queue.empty())
	{
		node* temp = tree_node_queue.front();
		tree_node_queue.pop_front();
		cout << temp->data << " ";
		if (temp->lchild != NULL)
		{
			tree_node_queue.push_back(temp->lchild);
		}
		if (temp->rchild != NULL)
		{
			tree_node_queue.push_back(temp->rchild);
		}
	}
}
void test01()
{
	node* root = NULL;
	root = CreateBinTree(); //创建一个棵树：ABD#E##FG###C##
	LevelOrder(root);
}
int main()
{
	test01();
	system("pause");
	return 0;
}
