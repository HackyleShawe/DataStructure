#include <stdio.h>
#define QueueSize  10

typedef struct node
{
	int data[QueueSize]; //数组
	int front; //队头
	int rear; //对尾
}LoopQueue;

int main()
{
	LoopQueue MyQueue;

	//初始化
	MyQueue.front = 0;
	MyQueue.rear = 0;

	//入队
	MyQueue.data[MyQueue.rear] = 100;
	MyQueue.rear = (MyQueue.rear + 1) % QueueSize; //不可以直接++，因为循环队列 最后一个元素的下一个下标可能是0号元素
	MyQueue.data[MyQueue.rear] = 200;
	MyQueue.rear = (MyQueue.rear + 1) % QueueSize;
	MyQueue.data[MyQueue.rear] = 300;
	MyQueue.rear = (MyQueue.rear + 1) % QueueSize;

	//出队
	MyQueue.front = (MyQueue.front + 1) % QueueSize;

	int len = (MyQueue.rear - MyQueue.front + QueueSize) % QueueSize;
	printf("此时循环队列长度：%d\n", len);

	//遍历
	for (int i = MyQueue.front; i != MyQueue.rear; i = (i + 1) % QueueSize)
	{
		printf("%d ", MyQueue.data[i]);
	}

	return 0;
}
