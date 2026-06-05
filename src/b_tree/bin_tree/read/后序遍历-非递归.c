//非递归后续遍历
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
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
void PostOrder(node* root)
{
	if (root == NULL)
	{
		return;
	}
	stack<node*> tree_node_stack_a;
	stack<node*> tree_node_stack_b;

	node* temp = root;
	tree_node_stack_a.push(temp);
	while (!tree_node_stack_a.empty())
	{
		temp = tree_node_stack_a.top();
		tree_node_stack_a.pop();
		if (temp->lchild != NULL)
		{
			tree_node_stack_a.push(temp->lchild);
		}
		if (temp->rchild != NULL)
		{
			tree_node_stack_a.push(temp->rchild);
		}
		tree_node_stack_b.push(temp);
	}
	while (!tree_node_stack_b.empty())
	{
		temp = tree_node_stack_b.top();
		tree_node_stack_b.pop();
		cout << temp->data << " ";
	}
}

void test01()
{
	node* root = NULL;
	root = CreateBinTree(); //创建一个棵树：ABD#E##FG###C##
	PostOrder(root);
}
int main()
{
	test01();
	system("pause");
	return 0;
}
