#define _CRT_SECURE_NO_WARNINGS  //宏
#include<stdio.h>
#include<stdlib.h>

typedef struct link
{
	int data;
	struct link *next;  //如何理解呢？这是一个结构体内存，在这个结构体内存里
	//保存了下一个结构体的首地址，这样不就一个一个连接起来了吗？
}node;
typedef node* linklist;
	//node:结点；

//function：初始化,置空，判断是否为空，显示，增【追加？排序式？指定式？】，删，改，查；
linklist Init();//初始化；
int MakeEmpty(linklist head);  //置空；
int IsEmpty(linklist head);  //判断是否为空；
void Dispaly(linklist head);  //显示单链表；

	//单链表增加：
void append(linklist head, int x);  //只增加一个元素；
void InsertSort(linklist head, int x);//排序式；
void oppoint(linklist head, int x,int n);//指定式；appoint:指定，委托；

void delete(linklist head, int x); //删除单链表的某个元素；
linklist find(linklist head, int x);//找某个元素；
void alter(linklist head, int x,int new); //修改某个元素； alter：其他的，改变的；

void destroy(linklist head); //毁灭单链表；