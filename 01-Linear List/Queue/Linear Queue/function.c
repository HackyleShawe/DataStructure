#include"queue.h"

queue init()
{
	queue sq;
	sq = (queue)malloc(sizeof(node));
	sq->data[SIZE] =0;
	sq->front=sq->rear=0; 
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
		int i=0,j=0;
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
				printf("%3d", a[i]+1);
				i += 1;
			}
		}		
	}
}