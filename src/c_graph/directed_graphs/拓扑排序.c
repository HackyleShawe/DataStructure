#include <stdio.h>
#include <stdlib.h>

#define MAXEDGE 20
#define MAXVEX 14
#define MY_INFINITY 65535

/* 邻接矩阵结构 */
typedef struct
{
	int vexs[MAXVEX]; //顶点集
	int matrix[MAXVEX][MAXVEX]; //邻接矩阵
	int numVertexes, numEdges; //顶点数，边数
}Graph;


/* 邻接表结构 */
typedef struct EdgeNode /* 边表结点  */
{
	int adjvex;  /* 邻接点域，存储该顶点对应的下标 */
	int weight;	/* 用于存储权值，对于非网图可以不需要 */
	struct EdgeNode *next; /* 链域，指向下一个邻接点 */
}EdgeNode;
typedef struct VertexNode /* 顶点表结点 */
{
	int in;	/* 顶点入度 */
	int data; /* 顶点域，存储顶点信息 */
	EdgeNode *firstedge;/* 边表头指针 */
}VertexNode;
typedef struct
{
	VertexNode list[MAXVEX];
	int numVertexes, numEdges; /* 图中当前顶点数和边数 */
}GraphAdjList;
/* **************************** */

//创建图的邻接矩阵
void CreateGraph(Graph *g)
{
	/*注意：
	如果在这里使用malloc，则录入的数据在本函数结束时就自动被删除了；
	于是需要在main函数为存储图的变量使用malloc，才会一直持续到程序结束！
	g = (Graph*)malloc(sizeof(Graph));
	*/
	int i, j, k, w;
	printf("输入顶点数和边数：\n");
	scanf("%d %d", &g->numVertexes, &g->numEdges);

	printf("输入顶点：\n");
	for (i = 0; i < g->numVertexes; i++)
	{
		scanf("%d", &g->vexs[i]);
	}

	//初始化邻接矩阵
	for (i = 0; i < g->numVertexes; i++)
	{
		for (j = 0; j < g->numVertexes; j++)
		{
			g->matrix[i][j] = 0; //初始化边到边的距离为0
		}
	}
	printf("输入顶点间的边信息：\n");
	for (k = 0; k < g->numEdges; k++)
	{
		printf("请输入边(vi,vj)上的标号i,j和该边上的权:");
		scanf("%d%d%d", &i, &j, &w);
		g->matrix[i][j] = w;
		//g->matrix[j][i] = g->matrix[i][j]; 因为是单向有向图，不不能自动使其双向
	}
	printf("创建邻接矩阵成功！\n");
}

//利用图的邻接矩阵创建邻接表
void CreateAdjList(Graph *g, GraphAdjList *gal) //g表示图的邻接矩阵，gal是图的邻接表
{
	int i, j;
	EdgeNode *e;

	gal->numEdges = g->numEdges;
	gal->numVertexes = g->numVertexes;

	for (i = 0; i < g->numVertexes; i++) //读入顶点信息，建立表头
	{
		gal->list[i].in = 0; //邻接表表头的入度为0
		gal->list[i].data = g->vexs[i];
		gal->list[i].firstedge = NULL;
	}

	for (i = 0; i < g->numVertexes; i++) //建立边表
	{
		for (j = 0; j < g->numVertexes; j++)
		{
			if (g->matrix[i][j] == 1)
			{
				e = (EdgeNode*)malloc(sizeof(EdgeNode));
				e->adjvex = j;
				e->next = gal->list[i].firstedge; //将第i个表头与边表连接
				gal->list[i].firstedge = e;
				gal->list[j].in++;
			}
		}
	}
	printf("利用图的邻接矩阵创建邻接表成功！\n");
}

void ShowALGraph(GraphAdjList *g)
{
	int i;
	printf("\n遍历邻接表：\n");
	for (i = 0; i < g->numVertexes; i++)
	{
		printf("V%d：->", i);

		EdgeNode *h = g->list[i].firstedge;
		while (h)
		{
			printf("%d->", h->adjvex);
			h = h->next;
		}
		printf("NULL\n");
	}
}

//拓扑排序算法，有则输出排序序列，无则输出0
int TopologicalSort(GraphAdjList *gal) //gal表示是图的邻接表
{
	EdgeNode *e;
	int i, k, gettop; //gettop是获取栈顶元素的临时变量
	int top = 0; //栈指针的下标
	int count = 0; //统计输出顶点的个数
	int *stack; //栈，保存入度为0的顶点

	stack = (int *)malloc(sizeof(int)*gal->numVertexes); //栈中最多存储图中的所有顶点

	for (i = 0; i < gal->numVertexes; i++) //遍历顶点，把入度为0的顶点入栈
	{
		if (0 == gal->list[i].in)
		{
			stack[++top] = i; //顶点入栈
		}
	}

	while (top != 0)
	{
		gettop = stack[top--]; //获取栈顶元素
		printf("顶点%d->", gal->list[gettop].data);
		count++;

		for (e = gal->list[gettop].firstedge; e; e = e->next) //遍历以gettop为表头的邻接表的链表
		{
			k = e->adjvex;
			if (!(--gal->list[k].in))
			{
				stack[++top] = k;
			}
		}
	}
	printf("\n");
	if (count < gal->numVertexes)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	Graph *g = (Graph*)malloc(sizeof(Graph));
	GraphAdjList *gal=(GraphAdjList*)malloc(sizeof(GraphAdjList));
	int result;

	CreateGraph(g); //创建邻接矩阵
	CreateAdjList(g, gal); //根据邻接矩阵创建邻接表

	ShowALGraph(gal);

	result = TopologicalSort(gal);
	if (result)
	{
		printf("拓扑排序成功！\n");
	}
	else
	{
		printf("此图没有拓扑排序！\n");
	}

	system("pause");
	return 0;
}

/*
测试输入：
14 20
0 1 2 3 4 5 6 7 8 9 10 11 12 13
0 4 1
0 5 1
0 11 1
1 2 1
1 4 1
1 8 1
2 5 1
2 6 1
2 9 1
3 2 1
3 13 1
4 7 1
5 8 1
5 12 1
6 5 1
8 7 1
9 10 1
9 11 1
10 13 1
12 9 1
*/