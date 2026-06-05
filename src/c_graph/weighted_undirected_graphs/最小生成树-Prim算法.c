/*
Prim算法的邻接矩阵实现

环境：VS2017 X86

建议：
1、直接观看有难度的话，可以从本文件夹的A系列开始看起，真正弄懂图从创建到遍历，再到各个算法；
2、我的博客有详解以及示例用的图：https://blog.csdn.net/ComputerGeekHack
3、推荐新手的数据结构入门书籍：《大话数据结构》
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
		printf(" \tv%d", i);
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

//Prim最小生成树算法
void MiniSpanTree_Prim(Graph *g)
{
	int min, i, j, k;
	int adjvex[MAX_VER]; //保存相关顶点下标
	int lowcost[MAX_VER]; //保存相关顶点间边的权值
	lowcost[0] = 0; //初始化第一个顶点权值为0，即V0加入生成树
	adjvex[0] = 0; //初始化第一个顶点下标为0

	for (i = 1; i < g->NumVertexes; i++) //循环所有顶点(下标为0的顶点除外)
	{
		lowcost[i] = g->e[0][i]; //把边上的权赋值给lowcost
		adjvex[i] = 0;
	}
	for (i = 1; i < g->NumVertexes; i++)
	{
		min = INFINITY; //初始化最小权值为无穷大
		j = 1; k = 0;
		while (j < g->NumVertexes) //循环全部顶点
		{
			if (lowcost[j] != 0 && lowcost[j] < min) //如果权值不为0，且权值小于min
			{
				min = lowcost[j]; //让当前权值成为最小值
				k = j; //将当前最小值的下标存入k
			}
			j++;
		}
		printf("(%d,%d)", adjvex[k], k); //打印当前顶点边中权值最小边
		lowcost[k] = 0;
		for (j = 1; j < g->NumVertexes; j++)
		{
			//若下标为k的顶点各边权值小于此前这些顶点未被加入生成树的权值
			if (lowcost[j] != 0 && g->e[k][j] < lowcost[j])
			{
				lowcost[j] = g->e[k][j]; //将较小的权值存入lowcoat
				adjvex[j] = k;
			}
		}
	}
}

int main()
{
	Graph *g;
	g = (Graph*)malloc(sizeof(Graph));
	CreateGraph(g);
	ShowGraph(g);
	printf("\n最小生成树：\n");
	MiniSpanTree_Prim(g);
	system("pause");
	return 0;
}

/*
//测试输入
9 15
A B C D E F G H I
0 1 10
0 5 11
1 2 18
1 6 16
1 8 12
2 3 22
2 8 8
3 4 20
3 6 24
3 7 16
3 8 21
4 5 26
4 7 7
5 6 17
6 7 19

//输出：
(0,1)(0,5)(1,8)(8,2)(1,6)(6,7)(7,4)(7,3)
*/