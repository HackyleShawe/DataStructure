
/*==================================新的开始 分割线==================================*/
/*二叉树的顺序存储结构*/
//二叉树的数组方式孩子存储结构
#define MAX 10
typedef struct node
{
	char data;
	int LeftChild, RightChild;
}node;
node tree[MAX];
int legth; //节点的实际个数；
int root; //存放根节点的数组下标；


/***********************************局部分割线************************************/


//二叉树的数组方式孩子、双亲存储结构
#define MAX 10
typedef struct node
{
	char data;
	int LeftChild, RightChild;
	int parent; //存放双亲的数组下标；
}node;
node tree[MAX];
int legth; //节点的实际个数；
int root; //存放根节点的数组下标；

/*==================================完结 分割线==================================*/



/*==================================新的开始 分割线==================================*/
/*二叉树的链式存储结构*/
typedef struct node
{
	char data;
	struct node *LeftChild, *RightChild;
	//struct node *parent; //有需要父节点的情况；
}BinNode;

typedef BinNode* BinTree;
BinTree root;
/*==================================完结 分割线==================================*/

