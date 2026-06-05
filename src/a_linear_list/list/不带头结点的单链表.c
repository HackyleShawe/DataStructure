#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef struct mynode
{
	int data;
	struct mynode* next;
}node;
typedef node LinkedList; //起个别名

/*===============================Start 函数申明================================*/
void InitList(LinkedList* MyList); //初始化
//增
node* GetNode(int value); //获取一个节点
LinkedList* InsertHead(LinkedList* MyList, int value); //头插法
void InsertTail(LinkedList* MyList, int value); //尾插法
void InsertPosition(LinkedList* MyList, int pos, int value); //在指定位置插入
//删
void DeleteNode(LinkedList* MyList, int key); //删除data域为key的结点
//改
void ModifyNode(LinkedList* MyList, int pos, int value); //修改pos位置点的值
//查
void IsEmpty(LinkedList* MyList); //判定是否为空
void PrintList(LinkedList* MyList); //显示单链表
/*===============================End 函数申明=================================*/

int main()
{
	LinkedList* MyList = NULL;
	InitList(MyList);
	int x = 7;
	int value = 0;
	int pos = 0;

	while (1)
	{
		printf("\n\n增=》1.头插法；2.尾插法；3.在指定位置插入\n");
		printf("删=》4.删除data域为key的节点\n");
		printf("改=》5.修改pos位置点的值\n");
		printf("查=》6.判定是否为空；7.显示单链表\n");

		printf("请选择：\n");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			printf("输入你要插入的值：");
			scanf("%d", &value);
			MyList = InsertHead(MyList, value);
			break;
		case 2:
			printf("输入你要插入的值：");
			scanf("%d", &value);
			InsertTail(MyList, value);
			break;
		case 3:
			printf("输入你要在哪里插入什么值：");
			scanf("%d %d", &pos, &value);
			InsertPosition(MyList, pos, value);
			break;
		case 4:
			printf("输入你要删除的值：");
			scanf("%d", &value);
			DeleteNode(MyList, value);
			break;
		case 5:
			printf("输入你要修改的位置和改为什么值：");
			scanf("%d", &pos);
			scanf("%d", &value);
			ModifyNode(MyList, pos, value);
			break;
		case 6:
			IsEmpty(MyList);
			break;
		case 7:
			PrintList(MyList);
			break;
		default:
			printf("输入有误，重试！\n");
			break;
		}
	}
}

/*
函数功能：初始化一个不带头节点的单链表
*/
void InitList(LinkedList* MyList)
{
	////assert(MyList != NULL);
	MyList = NULL;
}

/*
函数功能：获取一个节点
*/
node* GetNode(int value)
{
	node* NewNode = (node*)malloc(sizeof(node));
	assert(NewNode != NULL);
	NewNode->data = value;
	NewNode->next = NULL;
	return NewNode;
}

/*
函数功能：头插法
*/
LinkedList* InsertHead(LinkedList* MyList, int value)
{
	////assert(MyList != NULL);
	node* NewNode = GetNode(value);
	NewNode->next = MyList;
	MyList = NewNode;
	return MyList;
}

/*
函数功能：尾插法
*/
void InsertTail(LinkedList* MyList, int value)
{
	//assert(MyList != NULL);
	LinkedList* p = MyList;
	while (p->next != NULL)
	{
		p = p->next;
	}
	node* NewNode = GetNode(value);
	p->next = NewNode;
}

/*
函数功能：在指定位置插入
*/
void InsertPosition(LinkedList* MyList, int pos, int value)
{
	//assert(MyList != NULL);

	//计算链表长度
	int len = 0;
	LinkedList* p = MyList;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}

	//判定位置是否符合条件
	if (pos < 0 || pos>len)
	{
		printf("位置不合法！\n");
		return;
	}

	//执行插入
	p = MyList;
	for (int i = 0; i < pos - 1; i++)
	{
		p = p->next;
	}
	node* NewNode = GetNode(value);
	NewNode->next = p->next;
	p->next = NewNode;
}

/*
函数功能：删除data域为key的结点
*/
void DeleteNode(LinkedList* MyList, int key)
{
	//assert(MyList != NULL);
	LinkedList* p = MyList;
	LinkedList* t = p;
	while (p != NULL)
	{
		if (p->data == key)
		{
			t->next = p->next;
			//这里要释放删除的节点所在内存，暂不处理！
		}
		t = p;
		p = p->next;
	}
}

/*
函数功能：修改pos位置点的值
*/
void ModifyNode(LinkedList* MyList, int pos, int value)
{
	//assert(MyList != NULL);

	//计算链表长度
	int len = 0;
	LinkedList* p = MyList;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}

	//判定位置是否符合条件
	if (pos < 0 || pos>len)
	{
		printf("位置不合法！\n");
		return;
	}

	//执行插入
	p = MyList;
	for (int i = 0; i < pos - 1; i++)
	{
		p = p->next;
	}
	p->data = value;
}
/*
函数功能：判定是否为空
*/
void IsEmpty(LinkedList* MyList)
{
	if (MyList == NULL && MyList->next == NULL)
	{
		printf("\n链表为空！\n");
		return;
	}
	printf("\n链表不为空！\n");
}
/*
函数功能：显示单链表
*/
void PrintList(LinkedList* MyList)
{
	//assert(MyList != NULL);
	LinkedList* p = MyList;
	printf("\n单链表为：");
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}