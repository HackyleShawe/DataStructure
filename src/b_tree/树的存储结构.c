/**************************************Dividing Line******************************************/
// 双亲存储方式
// 本质：用一个结构体数组保存当前的具体数据和双亲的位置；

#define MAXSIZE 10 //树的节点个数；

typedef struct node
{
	char data; //该节点的具体值；
	int parent; //该节点的父节点的数组下标值；
}node;
typedef struct tree
{
	node TreeArray[MAXSIZE]; //存放各个节点的数组；
	int NodeNumber，root；//NodeNumber表示本树的所有节点的个数；root表示根节点的位置(一般为-1)；
}tree;

//tree.TreeArray[0]=A,-1




/**************************************Dividing Line******************************************/
// 数组方式孩子存储法

#define N 3 //表示每个节点所拥有得最大子女数是3个；即一个节点，只允许有最多3个小孩；
#define MAXSIZE 10  //表示本树的能存储最多10个节点；

typedef struct node
{
	char data;
	int child[N]; //child保存的是此data节点下的孩子的下标；
}node; //node是本结构体的新别名； 

node tree[MAXSIZE]; //存储树的节点；
int root； //根节点的下标；
int NodeNumber; //树的所有节点的个数；




/**************************************Dividing Line******************************************/
// 指针方式孩子存储法

#define N 3 //表示每个节点所拥有得最大子女数是3个；即一个节点，只允许有最多3个小孩；
typedef struct node
{
	char data;
	struct node *child[N];
}node, *tree; //node是本结构体的新别名；tree是结构体指针；
tree root; //结构体指针tree指向root；




/**************************************Dividing Line******************************************/
// 链表方式孩子存储法

#define MAXSIZE 10

typedef struct ChildNode //存储一个节点的在数组中的位置和下一个节点的地址；
{
	int child;
	struct ChildNode *NextChild;
}ChildNode, *ChildNodePoint;

typedef struct node
{
	char data;
	ChildNodePoint FirstChild;
}node;

typedef struct tree
{
	node TreeAyyary[MAXSIZE];
	int NodeNumber, root; //NodeNumber表示本个树总共含多少个节点，root表示根节点的位置；
}tree;




/**************************************Dividing Line******************************************/
// 孩子兄弟存储法

typedef struct node
{
	char data;
	struct node *FirstChild, *RightChild; //分别指向该节点的第一个子女和其右兄弟；
}node, *NodePoint;
NodePoint root; //声明结构体指针变量，同时也让节点指针指向root；




/**************************************Dividing Line******************************************/

