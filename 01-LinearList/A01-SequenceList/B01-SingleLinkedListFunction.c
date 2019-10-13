#include"SingleLinkedListHead.h"

linklist Init()
{//function:初始化一个单链表；
	//algorithm：尾插法
	/*设置一个辅助指针：assist和一个移动指针move；assist用于每次申请内存后存东西，move用于接上assist；最后返回head；*/

	linklist head = NULL;
	linklist assist, move = NULL;//创建head指针，和辅助指针；
	int x;
	printf("输入链表，以0为结束：   ");
	scanf("%d", &x);
	while (x != 0)
	{
		assist = (linklist)malloc(sizeof(node));
		assist->data = x;
		if (head == NULL) //就因为少了个”=“，把我害得好苦啊；
		{
			head = assist;
		}
		else
		{
			move->next = assist;
		}
		move = assist;  //move指针开始移动；
		scanf("%d", &x);
	}
	if (move) move->next = NULL;  //给指针加了个尾巴，表示此链表结束了；
	
	if (head == NULL) printf("初始化失败。\n");
	else printf("初始化成功。\n");
	return head;
}
/*//头插法code：

algorithm: 把assist每次申请空间存好数据，放在head的前面，再移动head(head=assist)
linklist HeadInsert()
{
	linklist head, assist;
	datatype x;
	head = NULL;
	printf("请输入若干整数序列:\n");
	scanf("%d", &x);
	while (x != 0)
	{
		assist = (linklist)malloc(sizeof(node));
		assist->info = x;
		assist->next = head;
		head = assist;
		scanf("%d", &x);
	}
	return head;
}*/
int MakeEmpty(linklist head)  //置空；
{
	head = NULL;
	if (head == NULL) return 0;  //确实为空；
	else return 1;
}
int IsEmpty(linklist head)  //判断是否为空；
{
	if (head == NULL) return 0;  //确实为空；
	else return 1;
}

void Dispaly(linklist head)
{
/*algorithm：判断是不是空链；设置一个移动指针move，不断移动move指针，输出data即可；*/
	linklist move;  //move代替head指针去跑；
	if (head == NULL)   //这里又把‘=’搞错了，，
	{
		printf("链表是空的，没法玩.\n");
		exit(0);
	}
	else
	{
		move = head;
		printf("此时链表的情况是：（head-->back）    ");

		while (move)
		{
			printf("%d",move->data);
			if (move->next != NULL) printf("-->");
			move = move->next;
		}
	}
}

/*“增”算法集*/
void append(linklist head, int x)
{//function:在链表追加x；
	linklist temp=NULL; //用于检测是否追加成功的结构体指针；

	if (head == NULL)  //此时是空链；
	{
		head = (linklist)malloc(sizeof(node)); 
		temp = head;//检测追加是否成功；
		head->data = x;
		head->next = NULL;
	}
	else
	{
		linklist move = NULL, assist = NULL;
		move = head;
		while (move->next!=NULL)//移动指针到当前链表的最后一个位置
		{
			move = move->next;
		}

		assist = (linklist)malloc(sizeof(node));
		assist->data = x;
		temp = assist;//检测追加是否成功；

		move->next = assist;
		assist->next = NULL;
	}
	if (temp == NULL) printf("追加失败.\n");
	else
	{
		printf("追加成功。\n");
	}
}
void InsertSort(linklist head, int x)
{
////////////////////////////////////
//	function:按照顺序插入到链表中；
//	algorithm:把x的内存空间分配好为save；判断是不是在链表的首位；
//		否则，move指针开始移动，满足条件break，不满足条件temp指针也紧跟着head指针前进；
//		然后把temp指针指向save，save指向move指针。
////////////////////////////////////
	linklist save;
	save = (linklist)malloc(sizeof(node));
	save->data = x;

	if (head->data >= x)//如果是首个元素就比x大；
	{
		save->next = head;
	}
	else
	{
		linklist move,temp;  //temp用于保存上一个结点的数据；
		temp = head;
		move = head->next;
		while (move)//找；
		{
			if (move->data >= x)break;
			else
			{
				temp = move;
				move = move->next;
			}
		}
		temp->next = save;//接上链表；
		save->next = move;
	}
}
void oppoint(linklist head, int x,int n)
{//function：指定在链表中的位置插入数据；
	/*algorithm：把要增加的数据分配内存保存为save；如果是在第一个位置插入，执行情况，否则先找到位置n；再接上即可；
	其中要设置assist是move的前一个；*/

	linklist move, assist;
	linklist save;
	save = (linklist)malloc(sizeof(node));
	save->data = x;
	int i;

	if (n == 1)//想要在第一个位置插入；
	{
		save->next = head;
		head = save;
	}
	else
	{
		move = head;
		assist = move;
		for (i = 1; i < n; i++)  //找；
		{
			assist = move;
			move = move->next;
		}
		assist->next = save;//接上；
		save->next = move;
	}
}
void delete(linklist head, int x)
{//删除某个元素；
	linklist move, assist;
	int t, save;
	if (head == NULL)
	{
		printf("链表是空的，没法玩.\n");
		exit(0);
	}
	else if (head->data == x) //第一个就是要删除的；
	{

		t = head->data;
		assist=head;
		assist = assist->next;
		head = assist;
		if (t == x) printf("没删除成功。\n");
		else printf("删除成功。\n");
	}
	else
	{
		move = head;
		assist = move;
		while (move) //找；
		{
			if (move->data == x)
			{
				t = move->data;break;
			}
			else
			{
				save = move->data;
				assist = move;
				move = move->next;
			}
		}
		move = move->next;
		assist->next = move;
		if(t==save) printf("没删除成功。\n");
		else printf("删除成功。\n");
	}
}

linklist find(linklist head, int x)
{//function：找到某个元素；
	linklist move;
	if (head == NULL)
	{
		printf("链表是空的，没法玩.\n");
		return NULL;
	}
	else
	{
		move = head;
		while (move)
		{
			if (move->data == x) break;
			else move = move->next;
		}
		return move;
	}
}
void alter(linklist head, int x,int new)
{//function:修改某个元素；
	int temp;
	linklist found = NULL;
	found = find(head, x);
	temp = found->data;
	found->data = new;
	if (found->data == temp)
		printf("没有修改成功。\n");
	else
		printf("修改成功。\n");
}


void destroy(linklist head)
{//function:毁灭此单链表；
	//algorithm:设置一个辅助指针，先向后移动head指针；free(assist);再把assist指针也向后移动；
		linklist assist = head;
		while (assist)
		{
			head = assist->next;
			free(assist);
			assist = head;
		}
		if (head == NULL)
			printf("删除成功。\n");
		else printf("删除失败。\n");
}