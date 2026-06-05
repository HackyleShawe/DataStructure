#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAXEDGE 20
#define MAXVEX 20
#define MY_INFINITY 65535

typedef struct
{
	int vexs[MAXVEX]; //保存边
	int matrix[MAXVEX][MAXVEX]; //保存邻接表
	int numVertexes, numEdges; //保存节点数，边数
}Graph;

//构造图
void CreateGraph(Graph *g)
{
	int i, j, k, w;
	printf("输入顶点数和边数：\n");
	scanf("%d%d", &g->numVertexes, &g->numEdges);

	for (i = 0; i < g->numVertexes; i++)
	{
		g->vexs[i] = i; //初始化图的各个顶点为0,1,2，……numVertexes
	}

	for (i = 0; i < g->numVertexes; i++) //初始化图的邻接矩阵
	{
		for (j = 0; j < g->numVertexes; j++)
		{
			if (i == j)
				g->matrix[i][j] = 0;
			else
				g->matrix[i][j] = g->matrix[j][i] = MY_INFINITY;
		}
	}

	printf("输入顶点间的边信息：\n");
	for (k = 0; k < g->numEdges; k++)
	{
		printf("请输入边(vi,vj)上的标号i,j和该边上的权:");
		scanf("%d%d%d", &i, &j, &w);
		g->matrix[i][j] = w;
		g->matrix[j][i] = g->matrix[i][j];
	}
}

void ShortestPath_Dijkstra(Graph G, int v0, int *pa, int *pv) //pa表示最短路径数组，pv表示最短路径的权和
{
	int v, w, k, min;
	int final[MAXVEX]; //表示已经求得V0到某顶点的最短路径，如final[w]=1表示求得顶点V0至Vw的最短路径
	
	for (v = 0; v<G.numVertexes; v++)//遍历顶点，初始化final数组、SPA数组，SPV数组
	{
		final[v] = 0; /* 全部顶点初始化为未知最短路径状态 */
		pv[v] = G.matrix[v0][v]; //将与v0点有连线的顶点加上权值
		pa[v] = -1;  //初始化路径数组为-1，表示没有任何路径
	}


	pv[v0] = 0; //v0至v0路径的权为0
	final[v0] = 1; //v0至v0不需要求路径

	for (v = 1; v<G.numVertexes; v++) //遍历顶点，每次求得V0到某个V顶点的最短路径
	{
		min = MY_INFINITY;   /* 当前所知离v0顶点的最近距离 */
		for (w = 0; w<G.numVertexes; w++)//遍历顶点，寻找离v0最近的顶点
		{
			if (!final[w] && pv[w]<min) //如果：w顶点没有被求过最短路径、找到还小的顶点
			{
				k = w;
				min = pv[w]; // w顶点离v0顶点更近
			}
		}
		final[k] = 1;  //将目前找到的最近的顶点置为1
		
		for (w = 0; w<G.numVertexes; w++) /* 修正当前最短路径及距离 */
		{
			/* 修正的条件是：经过V顶点的路径比现在这条路径的长度短的话 */
			if (!final[w] && (min + G.matrix[k][w] < pv[w]))/*  说明找到了更短的路径，修改D[w]和P[w] */
			{ 
				pv[w] = min + G.matrix[k][w];  /* 修改当前路径长度 */
				pa[w] = k;
			}
		}
	}
}

int main()
{
	int i, j, v0;
	Graph G;
	int ShortPathArray[MAXVEX]; /* 用于存储最短路径下标的数组 */
	int ShortPathValue[MAXVEX];	/* 用于存储到各点最短路径的权值和 */
	
	v0 = 0;

	CreateGraph(&G);

	ShortestPath_Dijkstra(G, v0, ShortPathArray, ShortPathValue);

	printf("最短路径倒序如下:\n");
	for (i = 1; i<G.numVertexes; ++i)
	{
		printf("v%d - v%d : ", v0, i);
		j = i;
		while (ShortPathArray[j] != -1)
		{
			printf("%d ", ShortPathArray[j]);
			j = ShortPathArray[j];
		}
		printf("\n");
	}
	printf("\n源点到各顶点的最短路径长度为:\n");
	for (i = 1; i<G.numVertexes; ++i)
		printf("v%d - v%d : %d \n", G.vexs[0], G.vexs[i], ShortPathValue[i]);
	system("pause");
	return 0;
}

/*
输入：
9 15
0 1 1
0 2 5
1 2 3
1 3 7
1 4 5
2 4 1
2 5 7
3 4 2
3 6 3
4 5 3
4 6 6
4 7 9
5 7 5
6 7 2
6 8 7
7 8 4
*/
