//前序非递归遍历二叉树
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

void RePreOrder(node* root)
{
	if (root !=NULL)
	{
		cout << root->data << "  ";
		RePreOrder(root->lchild);
		RePreOrder(root->rchild);
	}
}

/*
函数功能：
	非递归前序遍历
算法思想：
	1，维护一个栈，每次将根节点入栈；
	2，只要栈不为空，输出栈顶并弹出；
	3，将上一步中的栈顶的非空左右孩子压栈；
*/
void PreOrder(node* root)
{
	if (root == NULL)
	{
		return;
	}
	stack<node*> tree_node_stack;
	tree_node_stack.push(root);
	while (!tree_node_stack.empty())
	{
		node* temp = tree_node_stack.top();
		tree_node_stack.pop(); //STL中的pop只有弹出功能
		cout << temp->data << "  ";
		if (temp->rchild != NULL)
		{
			tree_node_stack.push(temp->rchild);
		}
		if (temp->lchild != NULL)
		{
			tree_node_stack.push(temp->lchild);
		}
	}
}

void test01()
{
	node* root = NULL;
	root = CreateBinTree(); //创建一个棵树：ABD#E##FG###C##
	PreOrder(root);
}
int main()
{
	test01();
	system("pause");
	return 0;
}
