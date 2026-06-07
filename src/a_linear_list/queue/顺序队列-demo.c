#include <stdio.h>
#define MAX 10

typedef struct node
{
	int data[MAX]; //数组
	int front; //队头
	int rear; //对尾
}queue;

int main()
{
	queue MyQueue;

	//初始化
	MyQueue.front = -1;
	MyQueue.rear = -1;

	//入队
	MyQueue.rear++;
	MyQueue.front++;
	MyQueue.data[MyQueue.rear] = 100;
	MyQueue.data[++MyQueue.rear] = 200;
	MyQueue.data[++MyQueue.rear] = 300;

	//出队
	MyQueue.front++;

	//遍历
	for (int i = MyQueue.front; i <= MyQueue.rear; i++)
	{
		printf("%d ", MyQueue.data[i]);
	}

	return 0;
}
