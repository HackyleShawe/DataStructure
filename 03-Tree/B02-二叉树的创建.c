

/*==================================新的开始 分割线==============================*/
/*二叉树的递归创建*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	struct node *lchild;
	struct node *rchild;
	char data;
}node;


node *CreateBinTree() //前序、递归方式来创建一颗二叉树
{
	node *p; //节点指针；
	char ch;
	if ((ch=getchar())=='#')
	{
		p = NULL;
	}
	else
	{
		p = (node*)malloc(sizeof(node));
		p->data = ch;
		p->lchild = CreateBinTree(); //创建左子树，记作L
		p->rchild = CreateBinTree();//创建右子树，记作R
	}
	return p;
}
void PreTraverse(node *t) //前序遍历
{
	if (t != NULL)
	{
		printf("%c", t->data);
		PreTraverse(t->lchild);
		PreTraverse(t->rchild);
	}
}

int main()
{
	node *root = NULL;
	root = CreateBinTree(); // ABD#E##FG###C##
	PreTraverse(root);

	system("pause");
	return 0;
}

/*==================================完结 分割线==================================*/
