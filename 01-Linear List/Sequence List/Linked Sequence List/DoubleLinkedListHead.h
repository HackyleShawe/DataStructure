#define _CRT_SECURE_NO_WARNINGS  //宏
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<string.h>
#include<Windows.h>
#include<math.h>

typedef struct d_l_l
{
	int data;
	struct d_l_l *next;
	struct d_l_l *pre;
}node;

typedef node* dlinklist;

dlinklist Init(); //创建一个双链表；
void Display(dlinklist head);  //正向显示双链表；
void ReverseDisplay(dlinklist head); //反向显示双链表；

void Find(dlinklist head,int x); //查找某个值；
void Insert(dlinklist head, int num, int position); //插入某个数；
void DeleteNumber(dlinklist head, int num); //删除一个数；