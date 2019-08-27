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
  
queue init();
void IsEmpty(queue sq);
void MakeEmpty(queue sq);
void display(queue sq);

void ComeIn(queue sq,int x);
void out(queue sq); 
void find(queue sq, int x);