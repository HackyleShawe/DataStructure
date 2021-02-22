


/*==================================新的开始 分割线==============================*/
/*
	DFS的邻接表实现
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define	MAX_SIZE 100
#define	TRUE 1
#define FALSE 0 

typedef int Boolean;
Boolean visited[MAX_SIZE]; //已经访问了的标志

typedef char VertexType; //顶点类型
typedef int EdgeType; //边上的权值类型

					  //保存邻接表上的信息
typedef struct EdgeNode
{
	int adjvex; //邻接点域，存储该顶点对应的下标
				//EdgeType weight; //边上的权值
	struct EdgeNode* next; //下一个邻接点
}EdgeNode;

//把整个图上的所有结点打包为一个数组
typedef struct VertexNode
{
	VertexType data; //顶点信息
	EdgeNode *firstedge; //边表头指针
}AdjList;

typedef struct
{
	AdjList list[MAX_SIZE]; //边表头数组
	int NumVertexes, NumEdges;//图的顶点数，边数
}GraphAdjList;


//创建图的邻接表
void  CreateALGraph(GraphAdjList *g)
{
	int i, j, k;
	EdgeNode *e;
	EdgeNode *t = NULL,*m=NULL; //辅助指针
	printf("输入顶点数和边数：\n");
	scanf("%d%d", &g->NumVertexes, &g->NumEdges);

	//现将所有结点保存在一个数组中
	printf("输入结点的data域的值：\n");
	for (i = 0; i < g->NumVertexes; i++)
	{
		scanf("%s", &g->list[i].data);
		g->list[i].firstedge = NULL; //将边表置为空
	}

	//创建邻接表
	for (k = 0; k < g->NumEdges; k++)
	{
		printf("输入边(vi,vj)上的顶点序号：\n");
		scanf("%d%d", &i, &j);

		//注意，以下是单链表的头插法
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = j; //邻接序号为j
		if (g->list[i].firstedge == NULL)
		{
			g->list[i].firstedge = e;
			t = e;
			t->next = NULL;
		}
		else
		{
			t = g->list[i].firstedge;
			m = t;
			while (t->next) { m = t; t = t->next; }
			t->next = e;
			t = t->next;
			t->next = NULL;
		}

		//e->next = g->list[i].firstedge;
		//g->list[i].firstedge = e;

		e = (EdgeNode*)malloc(sizeof(EdgeNode)); //因为是无向图，一条边对应都是两个顶点，所以在一次循环中针对i和j分别进行插入；
		e->adjvex = i;
		if (g->list[j].firstedge == NULL)
		{
			g->list[j].firstedge = e;
			t = e;
			t->next = NULL;
		}
		else
		{
			t = g->list[j].firstedge;
			m = t;
			while (t->next) { m = t; t = t->next; }
			t->next = e;
			t = t->next;
			t->next = NULL;
		}
		//e->next = g->list[j].firstedge;
		//g->list[j].firstedge = e;
	}
}
void ShowALGraph(GraphAdjList *g)
{
	int i;
	printf("\n图的邻接表：\n");
	for (i = 0; i < g->NumVertexes; i++)
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
//邻接表
void DFS(GraphAdjList *g, int i)
{
	EdgeNode *p;
	visited[i] = TRUE;
	printf("%c ", g->list[i].data); //打印顶点

	p = g->list[i].firstedge;
	while (p)
	{
		if (!visited[p->adjvex])
		{
			DFS(g, p->adjvex); //对为访问的邻接顶点递归调用
		}
		p = p->next;
	}
}
void DFS_traverse(GraphAdjList *g)
{
	int i;
	for (i = 0; i < g->NumVertexes; i++)
	{
		visited[i] = FALSE;
	}
	for (i = 0; i < g->NumVertexes; i++)
	{
		if (!visited[i]) //对未访问过的顶点调用DFS，若是连通图，则只会执行一次
		{
			DFS(g, i); //i表明，从那个顶点开始遍历
		}
	}
}
int main()
{
	GraphAdjList *g;
	g = (GraphAdjList*)malloc(sizeof(GraphAdjList));
	CreateALGraph(g);
	ShowALGraph(g);

	printf("\nDFS遍历结果：\n");
	DFS_traverse(g);
	system("pause");
	return 0;
}

//输入：
//注：边链表使用头插法会引起错误，应该使用尾插法；
//  此外，结点的顺序应该一致，例如："0 1"和"0 5"的输入顺序不能调换；
9 15
A B C D E F G H I
0 1
0 5
1 2
1 6
1 8
2 3
2 8
3 6
3 7
3 8
3 4
4 5
4 7
5 6
6 7

/*==================================完结 分割线==================================*/