/*
Kruskal算法的边集数组实现

环境：VS2017 X86

建议：
1、直接观看有难度的话，可以从本文件夹的A系列开始看起，真正弄懂图从创建到遍历，再到各个算法；
2、我的博客有详解以及示例用的图：https://blog.csdn.net/ComputerGeekHack
3、推荐新手的数据结构入门书籍：《大话数据结构》
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAXEDGE 20
#define MAXVEX 20
#define MY_INFINITY 65535

typedef struct
{
	char vertexes[MAXVEX];//图的顶点集
	int matrix[MAXVEX][MAXVEX]; //图的邻接矩阵
	int NumVertexes, NumEdges;
}Graph;

typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;

/*创建图*/
void CreateGraph(Graph *g)
{
	int i, j, k, w;
	printf("输入顶点数和边数：\n");
	scanf("%d %d", &g->NumVertexes, &g->NumEdges);

	printf("输入顶点：\n");
	for (i = 0; i < g->NumVertexes; i++)
	{
		scanf("%s", &g->vertexes[i]);
	}

	//初始化邻接矩阵
	for (i = 0; i < g->NumVertexes; i++)
	{
		for (j = 0; j < g->NumVertexes; j++)
		{
			g->matrix[i][j] = MY_INFINITY;
		}
	}
	printf("输入顶点间的边信息：\n");
	for (k = 0; k < g->NumEdges; k++)
	{
		printf("请输入边(vi,vj)上的标号i,j和该边上的权:");
		scanf("%d%d%d", &i, &j, &w);
		g->matrix[i][j] = w;
		g->matrix[j][i] = g->matrix[i][j];
	}
}

void Swapn(Edge *edges, int i, int j) //交换权值 以及头和尾
{
	int temp;
	temp = edges[i].begin;
	edges[i].begin = edges[j].begin;
	edges[j].begin = temp;
	temp = edges[i].end;
	edges[i].end = edges[j].end;
	edges[j].end = temp;
	temp = edges[i].weight;
	edges[i].weight = edges[j].weight;
	edges[j].weight = temp;
}
void sort(Edge edges[], Graph *G) //对权值进行排序
{
	int i, j;
	for (i = 0; i < G->NumEdges; i++)//冒泡
	{
		for (j = i + 1; j < G->NumEdges; j++)
		{
			if (edges[i].weight > edges[j].weight)
			{
				Swapn(edges, i, j);
			}
		}
	}
	printf("\n权排序之后的边为:\n");
	for (i = 0; i < G->NumEdges; i++)
	{
		printf("边：(%d, %d)； 权：%d\n", edges[i].begin, edges[i].end, edges[i].weight);
	}
	printf("\n");
}

int Find(int *parent, int f) //查找连线顶点的尾部下标
{
	while (parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}
void MiniSpanTree_Kruskal(Graph G)
{
	int i, j, n, m;
	int k = 0;
	int parent[MAXVEX];/* 定义一数组用来判断边与边是否形成环路 */

	Edge edges[MAXEDGE];/* 定义边集数组,edge的结构为begin,end,weight,均为整型 */
						/* 用来构建边集数组并排序********************* */
	
	//把图中的数据转移到边集数组中
	for (i = 0; i < G.NumVertexes - 1; i++) 
	{
		for (j = i + 1; j < G.NumVertexes; j++)
		{
			if (G.matrix[i][j] < MY_INFINITY)
			{
				edges[k].begin = i;
				edges[k].end = j;
				edges[k].weight = G.matrix[i][j];
				k++;
			}
		}
	}
	sort(edges, &G);

	for (i = 0; i < G.NumVertexes; i++) //初始化数组值为0
		parent[i] = 0;

	printf("打印最小生成树：\n");
	for (i = 0; i < G.NumEdges; i++) //循环每一条边
	{
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);
		if (n != m) /* 假如n与m不等，说明此边没有与现有的生成树形成环路 */
		{
			parent[n] = m;	//将此边的结尾顶点放入下标为起点的parent中。表示此顶点已经在生成树集合中
			printf("边(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}

int main(void)
{
	Graph G;
	CreateGraph(&G);
	MiniSpanTree_Kruskal(G);
	system("pause");
	return 0;
}


/*
测试
输入：
9 15
A B C D E F G H I （就是V0~V8的意思）
0 1 10
0 5 11
1 2 18
1 8 12
1 6 16
2 8 8
2 3 22
3 8 21
3 6 24
3 7 16
3 4 20
4 7 7
4 5 26
5 6 17
6 7 19

输出：
打印最小生成树：
边(4, 7) 7
边(2, 8) 8
边(0, 1) 10
边(0, 5) 11
边(1, 8) 12
边(3, 7) 16
边(1, 6) 16
边(6, 7) 19

*/