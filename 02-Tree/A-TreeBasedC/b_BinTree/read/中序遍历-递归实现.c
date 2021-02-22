#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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

void ReMiddleOrder(node* root)
{
	if (root != NULL)
	{
		ReMiddleOrder(root->lchild);
		cout << root->data << "  ";
		ReMiddleOrder(root->rchild);
	}
}

void test01()
{
	node* root = NULL;
	root = CreateBinTree(); //创建一个棵树：ABD#E##FG###C##
	ReMiddleOrder(root);
}
int main()
{
	test01();
	system("pause");
	return 0;
}
