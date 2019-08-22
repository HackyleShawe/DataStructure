


/*==================================新的开始 分割线==============================*/
/*
	有向图的邻接矩阵
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef char VertextType; //顶点类型
typedef int EdgeType; //边双的权值类型
#define MAX_VER 1000 //最大顶点数
#define INFINITY 65535 //定义无穷大

typedef struct
{
	VertextType v[MAX_VER]; //顶点表
	EdgeType e[MAX_VER][MAX_VER]; //边的邻接矩阵
	int NumVertexes, NumEdges; //顶点数，边数
}Graph;

void CreateGraph(Graph *g)
{
	int i, j, k, w;
	printf("输入顶点数和边数：\n");
	scanf("%d %d", &g->NumVertexes, &g->NumEdges);

	printf("输入顶点：\n");
	for (i = 0; i < g->NumVertexes; i++)
	{
		scanf("%s", &g->v[i]);
	}
	
	//初始化邻接矩阵
	for (i = 0; i < g->NumVertexes; i++)
	{
		for (j = 0; j < g->NumVertexes; j++)
		{
			g->e[i][j] = INFINITY;
		}
	}
	printf("输入顶点间的边信息：\n");
	for (k = 0; k < g->NumEdges; k++)
	{
		printf("请输入边(vi,vj)上的标号i,j和该边上的权:");
		scanf("%d%d%d", &i, &j, &w);
		g->e[i][j] = w;
		g->e[j][i] = g->e[i][j];
	}
}

void ShowGraph(Graph *g)
{
	int i, j;

	printf("\n\n图的邻接矩阵为：\n");
	for (i = 0; i < g->NumVertexes; i++)
	{
		printf(" \tv%d",i);
	}
   printf("\n");
	for (i = 0; i < g->NumVertexes; i++)
	{
		printf("v%d\t", i);
		for (j = 0; j < g->NumVertexes; j++)
		{
			printf("%d\t", g->e[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	Graph *g;
	g = (Graph*)malloc(sizeof(Graph));
	CreateGraph(g);
	ShowGraph(g);
	system("pause");
	return 0;
}

/*测试：运行程序，直接将以下数据复制到控制台(鼠标右键,使用Ctrl+V无效)即可
5 6
A
B
C
D
E
0 1 9
1 2 3
0 2 2
0 4 6
4 3 1
2 3 5
*/

/*==================================完结 分割线==================================*/



/*==================================新的开始 分割线==============================*/
/*
	高级：有向图的邻接表，指针实现
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct ListEdgeNode {
	int index;                    // 边的下标
	struct ListEdgeNode *next;            // 指向下一个节点的指针
}ListEdgeNode;

typedef struct ListVertexNode {
	char vertex;            // 顶点
	ListEdgeNode *fistEdge;        // 指向第一条边
} ListVertexNode;

typedef struct GraphList {
	int vertexNumber;            // 顶点的数量
	int edgeNumber;                // 边的数量
	ListVertexNode *vertex;        // 顶点集合，动态数组
}GraphList;


void CreateGraphList(GraphList *g)
{
	printf("请分别输入图的顶点数量和边的数量，用空格隔开：");
	scanf("%d %d", &g->vertexNumber, &g->edgeNumber); //将顶点数量和边的数量存储在结构体g中相应的变量

													  //为动态数组申请空间
	g->vertex = (ListVertexNode*)malloc(g->vertexNumber * sizeof(ListVertexNode));
	//初始化顶点指的第一条边
	for (int i = 0; i < g->edgeNumber; i++) {
		g->vertex[i].fistEdge = NULL;
	}

	//输入图的信息
	ListEdgeNode *listEdgeNode;
	for (int k = 0; k < g->edgeNumber; k++) {
		int i, j;
		printf("请输入边(vi,vj)的下标, i和j，用空格隔开:");
		scanf("%d%d", &i, &j);
		//始终将插入的节点放在顶点所指的地一条边
		listEdgeNode = (ListEdgeNode *)malloc(sizeof(ListEdgeNode));
		listEdgeNode->index = j;
		listEdgeNode->next = g->vertex[i].fistEdge;
		g->vertex[i].fistEdge = listEdgeNode;

		listEdgeNode = (ListEdgeNode*)malloc(sizeof(ListEdgeNode));
		listEdgeNode->index = i;
		listEdgeNode->next = g->vertex[j].fistEdge;
		g->vertex[j].fistEdge = listEdgeNode;

	}

	//输出图的信息
	ListEdgeNode * len = NULL;
	for (int i = 0; i < g->vertexNumber; i++) {

		if (g->vertex[i].fistEdge != NULL)
			len = g->vertex[i].fistEdge;
		while (len != NULL) {
			printf("%d --- %d\t", i, len->index);
			len = len->next;
		}
		printf("\n");
	}
}

int main()
{
	GraphList *gl;
	gl = (GraphList*)malloc(sizeof(GraphList));
	CreateGraphList(gl);

	system("pause");
	return 0;
}
/*==================================完结 分割线==================================*/