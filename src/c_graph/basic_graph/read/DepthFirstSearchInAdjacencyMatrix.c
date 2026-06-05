


/*==================================新的开始 分割线==============================*/
/*
	DFS的邻接矩阵实现
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_VER 1000 //最大顶点数
#define INFINITY 65535 //定义无穷大
#define TRUE 1
#define FALSE 0
typedef char VertextType; //顶点类型
typedef int EdgeType; //边双的权值类型

typedef struct
{
	VertextType v[MAX_VER]; //顶点表
	EdgeType e[MAX_VER][MAX_VER]; //边的邻接矩阵
	int NumVertexes, NumEdges; //顶点数，边数
}Graph;

typedef int Boolean;
Boolean visited[MAX_VER]; //访问标志数组

void DFS(Graph *g, int i)
{
	int j;
	visited[i] = TRUE;
	printf("%c ", g->v[i]); //打印顶点

	for (j = 0; j < g->NumVertexes; j++)
	{
		if (g->e[i][j] == 1 && !visited[j])
		{
			DFS(g, j);
		}
	}
}
void DFS_traverse(Graph *g)
{
	int i;
	for (i = 0; i < g->NumVertexes; i++)
	{
		visited[i] = FALSE; //将所有顶点状态初始化为未访问状态
	}
	for (i = 0; i < g->NumVertexes; i++)
	{
		if (!visited[i]) //对未访问过的顶点调用DFS，如果是连通图，则执行一次
		{
			DFS(g, i); //i表明，从那个顶点开始遍历
		}
	}
}

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

int main()
{
	Graph *g;
	g = (Graph*)malloc(sizeof(Graph));
	CreateGraph(g);
	ShowGraph(g);

	printf("\nDFS遍历结果为：\n");
	DFS_traverse(g);
	system("pause");
	return 0;
}

//测试输入
//注：为了简单计算，把每条边的权值设为99；测试使用的图就是上文“理解DFS”的那个图
9 15
A B C D E F G H I
0 1 99
0 5 99
1 2 99
1 8 99
1 6 99
2 8 99
2 3 99
3 8 99
3 6 99
3 7 99
3 4 99
4 7 99
4 5 99
5 6 99
6 7 99

/*==================================完结 分割线==================================*/