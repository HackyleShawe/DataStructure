#define _CRT_SECURE_NO_WARNINGS  //宏
#include<stdio.h>
#include<stdlib.h>
/*reflection：无算法，不代码！*/
/*algorithm:一个单链表加上一个队列首尾指针；*/

typedef struct link_queue
{//定义存储数据的单链表；
	int data;
	struct link_queue *next;
}node;

typedef struct
{//定义队首队尾指针；
	node *front, *rear;//申明两个node型结构体指针，front用来保存头，rear用来保存尾巴；
}queue;

//初始化，置空，判断是否为空,显示；
void init(queue *qu); //初始化一个链式队列；
void MakeEmpty(queue *qu); //置空；
void IsEmpty(queue *qu); //判读为空;
void display(queue *qu); //显示;
//增删改查；
void input(queue *qu, int x);
void OutQueue(queue *qu);
void find(queue *qu, int x);