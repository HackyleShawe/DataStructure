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
