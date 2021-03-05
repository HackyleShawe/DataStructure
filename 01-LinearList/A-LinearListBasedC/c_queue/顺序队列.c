#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

typedef struct sequence_queue
{/*algorithm:本质上是一个数组，用两个数来保存数组现在位置的下标；*/
	int data[SIZE];
	int front;
	int rear;
}node;
typedef node* queue;



queue init()
{
	queue sq;
	sq = (queue)malloc(sizeof(node));
	sq->data[SIZE] = 0;
	sq->front = sq->rear = 0;
	return sq;
}
void IsEmpty(queue sq)
{
	if (sq->front == 0 && sq->rear == 0)
	{
		printf("THE SEQUENCE QUEUE IS EMPTY!\n");
	}
	else
	{
		printf("THE SWQUENCE QUEUE IS NOT EMPTY!\n");
	}
}
void MakeEmpty(queue sq)
{
	if (sq->front == 0 && sq->rear == 0)
		printf("THE SEQUENCE QUEUE IS EMPTY!\n");
	else
	{
		sq->front = 0;
		sq->rear = 0;
		if (sq->front == 0 && sq->rear == 0)
			printf("MAKE THE QUEUE TO EMPTY IS SUCCESSFUL!\n");
		else
		{
			printf("MAKE THE QUEUE TO EMPTY IS FAILURE!\n");
		}
	}
}
void display(queue sq)
{
	if (sq->front == 0 && sq->rear == 0) printf("HTE QUEUE IS EMPTY.CAN NOT FINISH IT.\n");
	else
	{
		printf("此时队列的情况是：  ");
		int i;
		for (i = sq->front; i < sq->rear; i++)
		{
			printf("%3d", sq->data[i]);
		}
		putchar('\n');
	}
}
void ComeIn(queue sq, int x) //入队列；
{
	if (sq->rear == SIZE - 1)
	{
		printf("THE QUEUE IS FULL,CAN NOT COME IN ELEMENT.\n");
	}
	else
	{
		int temp;
		temp = sq->rear;
		sq->data[sq->rear++] = x;
		if (temp == sq->rear) printf("COME IN THE QUEUE IS FAILURE!\n");
		else printf("COME IN THE QUEUE IS SUMCCESSFUL!\n");
	}
}
void out(queue sq) //出队列；
{
	if (sq->front == 0 && sq->rear == 0) printf("THE SEQUENCE QUEUE IS EMPTY!\n");
	else
	{
		printf("出队列的元素是：");
		printf("%3d\n", sq->data[sq->front]);
		sq->front += 1;
	}
}
void find(queue sq, int x) //查找某个元素；
{
	if (sq->front == 0 && sq->rear == 0)
		printf("THE SEQUENCE QUEUE IS EMPTY!\n");
	else
	{
		int i = 0, j = 0;
		int a[SIZE] = { 0 };
		for (i = sq->front; i <= sq->rear; i++)
		{
			if (x == sq->data[i])
				a[j++] = i;
		}
		i = 0;
		if (a[i] == 0)
		{
			printf("NOT FOUND.\n");
		}
		else
		{
			printf("FOUND!locate is \n");
			while (a[i] != 0)
			{
				printf("%3d", a[i] + 1);
				i += 1;
			}
		}
	}
}


/*
algorihtm:
 用一个数组来保存数据，用fornt来保存队列的头部的【即数组的下标】，用rear来保存队列的尾部；
 入队列是rear++；出队列时front++;
*/
int main()
{
	printf("――――――――――――实现线性队列――――――――――――");
	queue sq; //sequence queue:线性队列；
	sq = init();
	if (sq->front == 0 && sq->rear == 0) printf("\n初始化成功！\n");
	else printf("\n初始化失败！\n");

	while (1)
	{
		printf("\n选择你要做的事情：1:判断队列是否为空；   2：置空队列；   3：显示队列；\n");
		printf("4:入队列；   5：出队列；   6：查找队列中的某个元素；\n");
		int event;
		scanf("%d", &event);
		if (event == 1)
		{
			IsEmpty(sq);
		}
		else if (event == 2)
		{
			MakeEmpty(sq);
		}
		else if (event == 3)
		{
			display(sq);
		}
		else if (event == 4)
		{
			int i;
			for (i = 1; i < 11; i++)
				ComeIn(sq, i);
		}
		else if (event == 5)
		{
			int j = 0;
			for (; j < 3; j++)
				out(sq);
		}
		else if (event == 6)
		{
			int x;
			printf("PUT IN YOU WILL BE FIND THE NUMBER: ");
			scanf("%d", &x);
			find(sq, x);
		}
		else
		{
			printf("输入错误！重新输入！\n");
		}
	}

}