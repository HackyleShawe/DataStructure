#define _CRT_SECURE_NO_WARNINGS  //宏
#include<stdio.h>
#include<stdlib.h>
/*reflection：无算法，不代码！*/
/*algorithm:一个单链表加上一个队列首尾指针；*/

typedef struct link_queue
{//定义存储数据的单链表；
	int data;
	struct link_queue* next;
}node;

typedef struct
{//定义队首队尾指针；
	node* front, * rear;//申明两个node型结构体指针，front用来保存头，rear用来保存尾巴；
}queue;


void init(queue* qu)
{
	qu->front = qu->rear = (node*)malloc(sizeof(node));
	qu->front->next = NULL;
	if (qu->front->next == NULL) printf("初始化成功！\n");
	else printf("初始化失败！\n\n");
}
void MakeEmpty(queue* qu)
{
	node* move = qu->front->next; //找到单链表的开始结点；
	node* temp;
	while (move)
	{
		temp = move;
		move = move->next;
		free(temp);
	}
	move = qu->front;
	qu->front = NULL; qu->rear = NULL;
	free(move);
	if (qu->front == NULL && qu->rear == NULL) printf("置空队列成功！\n");
	else printf("置空队列失败！\n\n");
}
void IsEmpty(queue* qu)
{
	if (qu->front == qu->rear) printf("队列为空！\n");
	else printf("队列不为空！\n\n");
}
void display(queue* qu)
{
	if (qu->front == qu->rear) printf("队列为空！\n");
	else
	{
		node* move = qu->front->next;
		printf("此时队列中的情况是： （头-->尾）  ");
		while (move->next)
		{
			printf("%d", move->data);
			if (move->next != NULL) printf("==");
			move = move->next;
		}
		printf("%d", move->data);
		putchar('\n');
	}
}
void input(queue* qu, int x)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->data = x;
	temp->next = NULL;
	if (qu->front == NULL) //队列为空；
	{
		qu->front = qu->rear = temp;
	}
	else
	{
		qu->rear->next = temp;
		qu->rear = temp;
	}


}
void OutQueue(queue* qu)
{
	if (qu->front == qu->rear)
	{
		printf("队列为空！无法出队列。\n");
	}

	else
	{
		node* temp = qu->front;
		//temp = temp->next;
		qu->front = temp->next;
		free(temp);
		if (qu->front == NULL) qu->rear = NULL;
	}
}
void find(queue* qu, int x)
{
	node* move;
	int location = 0;
	move = qu->front;
	while (move->next != NULL)
	{
		if (move->data == x)
			printf("location is no.%d;\n", location);
		location += 1;
		move = move->next;
	}
}


int main()
{
	printf("――――――――――――链式队列的实现――――――――――――\n");
	queue qu;  //区分queue *qu;和queue qu;    
				/*queue qu;是向内存申请一片内存； queue *qu;是定义一个queue类型的指针；*/
	init(&qu);

	while (1)
	{
		printf("\n选择你要做的事：\n");
		printf("1:置空队列；  2：判断是否为空；  3：显示队列；  4:进入；\n");
		printf("5:出队列（删）；   6：查找；\n");
		int event;
		scanf("%d", &event);
		if (event == 1)
		{
			MakeEmpty(&qu);
		}
		else if (event == 2)
		{
			IsEmpty(&qu);
		}
		else if (event == 3)
		{
			display(&qu);
		}
		else if (event == 4)
		{
			/*int x;
			printf("输入你要进入的数据：");
			scanf("%d", &x);*/
			int i;
			for (i = 1; i <= 5; i++)
				input(&qu, i);
		}
		else if (event == 5)
		{
			OutQueue(&qu);
		}
		else if (event == 6)
		{
			int x;
			printf("输入你要查找的数据：");
			scanf("%d", &x);
			find(&qu, x);
		}
		else
		{
			printf("输出错误，本次输入无效！\n");
		}
	}
	system("pause");
	return 0;
}
