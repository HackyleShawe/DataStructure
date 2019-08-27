#include"link_queue.h"
void init(queue *qu)
{
	qu->front = qu->rear = (node*)malloc(sizeof(node));
	qu->front->next = NULL;
	if(qu->front->next == NULL) printf("初始化成功！\n");
	else printf("初始化失败！\n\n");
}
void MakeEmpty(queue *qu)
{
	node *move = qu->front->next; //找到单链表的开始结点；
	node *temp;
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
void IsEmpty(queue *qu)
{
	if (qu->front == qu->rear) printf("队列为空！\n");
	else printf("队列不为空！\n\n");
}
void display(queue *qu)
{
	if (qu->front == qu->rear) printf("队列为空！\n");
	else
	{
		node *move = qu->front->next;
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
void input(queue *qu, int x)
{
	node *temp = (node*)malloc(sizeof(node));
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
void OutQueue(queue *qu)
{
	if (qu->front == qu->rear)
	{
		printf("队列为空！无法出队列。\n");
	}
	
	else
	{
		node *temp = qu->front;
		//temp = temp->next;
		qu->front = temp->next;
		free(temp);
		if (qu->front == NULL) qu->rear = NULL;
	}
}
void find(queue* qu, int x)
{
	node *move;
	int location = 0;
	move = qu->front;
	while (move->next!=NULL)
	{
		if (move->data == x)
			printf("location is no.%d;\n", location);
		location += 1;
		move = move->next;
	}
}