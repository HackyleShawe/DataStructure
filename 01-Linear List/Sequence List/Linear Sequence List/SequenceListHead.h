#define _CRT_SECURE_NO_WARNINGS  //宏
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAXSIZE 20  //数据类型的容量；

typedef int datatype;
typedef struct sl{
	datatype myarray[MAXSIZE];
	int length; //线性表的长度；length<=MAXSIZE;
}SequenceList;
		//顺序表；  sequence 顺序的；  list：列表；

//增删改查
int GoToZero(SequenceList *list);//使顺序表归为0；
int RandInit(SequenceList *list);//随机初始化；
int PutInit(SequenceList *list); //手动初始化；

void display(SequenceList *list);  //显示顺序表；
int append(SequenceList *list,datatype x);  //在线性表后追加数据；
int JudgeEmpty(SequenceList *list);  //判断顺序表是否为空；

int Delete(SequenceList *list, int postion);  //删除顺序表中的x；
int FindNumber(SequenceList *list, int num);  //查找顺序表中的num；
