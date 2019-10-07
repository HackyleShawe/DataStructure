#define _CRT_SECURE_NO_WARNINGS  //宏
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#define MAX 100
/*Stack:栈，LIFO：后进先出表；*/
typedef struct mystack
{
	int mystack[MAX];  //栈的容量，其实就是一个竖起来的特殊数组！
	int top;  //用于指向栈顶，从而判断栈的状态；
}SequenceStack;

int MakeEmpty(SequenceStack *stack);   //创建一个空栈、初始化；
int JudgeIsEmpty(SequenceStack *stack);  //判断栈是否为空；

int push(SequenceStack *stack, int x);  //进栈；
int pop(SequenceStack *stack);  //出栈；
void ShowStack(SequenceStack *stack);  //显示栈的情况；