#include "SequenceListHead.h"

int GoToZero(SequenceList *list)
{//function:使顺序表的数据全部置为0；
//algorithm:循环使数组元素全成0，长度也置空为0；
	int i;
	for (i = 0; i < MAXSIZE; i++)
	{
		list->myarray[i] = 0;
	}
	list->length = 10; //
	if (list->length == 10)
	{
		return 1;  //表示置空成功，否则失败；
	}
	else
	{
		return 0;
	}
}
int RandInit(SequenceList *list)
{//function：随机获得元素；
	//algorithm:使用srand函数获得；
	time_t ts;//也可以不用这个，直接srand(time(NULL));
	srand((unsigned int)time(&ts));
	int i,flag=0;
	for (i = 0; i < list->length; i++)
	{
		list->myarray[i] = rand() % 100;
	}

	for (i = 0; i < list->length; i++)
	{//检测是不是都赋值成功了；
		if (list->myarray[i] >= 0) //reflect:这里的条件可改为：list->myarray[i] > -1
		{
			flag = 1;  //表示赋值是成功的；
		}
		else
		{
			flag = 0;  //赋值不成功；
			break;
		}
	}
	if (flag == 1) return 1;
	else  return 0;
}

int PutInit(SequenceList *list)
{//手动输入初始化顺序表
	int num,flag=0; 
	scanf("%d", &num);
	int i;
	for (i = 0; i < list->length; i++)
	{
		list->myarray[i] = num;
		scanf("%d", &num);
	}
		//检测是不是都赋值成功了；
	for (i = 0; i < list->length; i++)
	{
		if (list->myarray[i] >= 0) //reflect：这里的条件改可改为：list->myarray[i] > -1
		{
			flag = 1;  //表示赋值是成功的；
		}
		else
		{
			flag = 0;  //赋值不成功；
			break;
		}
	}
	if (flag == 1) return 1;
	else  return 0;

}
void display(SequenceList *list)
{
	int i;
	for (i = 0; i < list->length; i++)
	{
		printf("%3d", list->myarray[i]);
	}
	printf("\n");
}

int append(SequenceList *list,datatype x)
{//function:给顺序表追加数据；
//list->length += 1;为甚不加这一句呢？因为数组是以0为开始的；但是考虑到要在后来display，所以在后面还是要再加一的；
	if (list->length == MAXSIZE)
	{
		printf("顺序表已经满了。");
		exit(0);
	}
	list->myarray[list->length] = x;
	if (list->myarray[list->length] > 0)
	{
		list->length += 1;
		return 1;  //表示追加成功；
	}
	else return 0;
}

int JudgeEmpty(SequenceList *list)
{
	if (list->length == 0 || list->myarray[0] == 0)
		return 0; //真的是为空
	else return 1;  //不为空；
}
int Delete(SequenceList *list,int postion)
{//function:删除某个位置的元素；
	int i = 0, j = 0;
	int t;
		//find postion
	while (i != postion - 1)
	{
		i+=1;
	}
		//move data
	for (; i < list->length - 1; i++)
	{
		list->myarray[i] = list->myarray[i + 1];
	}
	list->length -= 1; //长度减少1个；
	if (i == list->length )
	{
		return 1;
	}
	else return 0;
}

int FindNumber(SequenceList *list, int num)
{//查找num，成功返回num以及所在位置，否则返回0；
	int i,flag = 0;
	for (i = 0; i < list->length; i++)
	{
		if (num == list->myarray[i])
		{
			flag = 1;  //已经找到；
			return i;
			break;
		}
	}
	if (flag == 0) return 0;  //没有找到；

}
