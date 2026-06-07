#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef struct link_queue
{ //定义存储数据的单链表；
	int data;
	struct link_queue* next;
}node;

typedef struct
{ //定义队首队尾指针；
	node* front, * rear;//申明两个node型结构体指针，front用来保存头，rear用来保存尾巴；
}queue;

void push(queue* MyQueue, int value)
{
	assert(MyQueue != NULL);
	node* NewNode = (node*)malloc(sizeof(node));
	assert(NewNode != NULL);
	NewNode->data = value;

	if (MyQueue->front == NULL  && MyQueue->rear == NULL) //空队列
	{
		MyQueue->front = NewNode;
	}
	else
	{
		MyQueue->rear->next = NewNode;
	}
	MyQueue->rear = NewNode;
}

int pop(queue* MyQueue)
{
	assert(MyQueue != NULL);
	node* tmp = MyQueue->front;
	int value = tmp->data;
	MyQueue->front = tmp->next;

	if (MyQueue->front == NULL)  // 最后一个节点出队的时候
	{
		MyQueue->rear = NULL;
	}
	free(tmp);
	tmp = NULL;
	return value;
}

int main()
{
	queue* MyQueue = (queue*)malloc(sizeof(queue));
	assert(MyQueue != NULL);

	MyQueue->front = NULL;
	MyQueue->rear = NULL;

	push(MyQueue, 100);
	push(MyQueue, 200);
	push(MyQueue, 300);
	push(MyQueue, 400);

	pop(MyQueue);
	pop(MyQueue);

	node* p = MyQueue->front;
	assert(p != NULL);
	while (p != MyQueue->rear->next)
	{
		printf("%d  ", p->data);
		p = p->next;
	}

	return 0;
}
