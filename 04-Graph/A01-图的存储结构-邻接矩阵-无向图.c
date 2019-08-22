


/*==================================新的开始 分割线==============================*/
/*
高级：无向图的邻接矩阵存储，指针实现
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
/*
牛逼的指针形式二维动态数组的使用方式；
a.声明：int **a;
b.给内存：a=(int **)malloc(二维数的行数 * seizeof(int));
for(i=0;i<二维数组的行数;i++)
a[i]=(int *)malloc(每行有多少个元素 * sizeof(int));
c.即可以如常规的二维数组使用；
*/

typedef struct graph
{
	int vertexNumber; //顶点数量；
	int edgeNumber; //边的数量；
	char * vertex; //顶点的集合；
	int **edge; //边集合，二维动态数组；
}GraphMatrix;

void CreateGraphMatrix(GraphMatrix *g) {

	printf("请分别输入图的顶点数量和边的数量，用空格隔开：");
	scanf("%d %d", &g->vertexNumber, &g->edgeNumber);  //将顶点数量和边的数量存储在结构体g中相应的变量

	g->vertex = (char*)malloc(g->vertexNumber * sizeof(char)); //为动态数组申请空间										  
	g->edge = (int**)malloc(g->vertexNumber * sizeof(int)); //二维动态数组申请空间

	for (int i = 0; i < g->vertexNumber; i++) {
		g->edge[i] = (int*)malloc(g->vertexNumber * sizeof(int));
	}
	//初始化邻接矩阵的所有元素为0；
	for (int i = 0; i < g->vertexNumber; i++) {
		for (int j = 0; j < g->vertexNumber; j++)
			g->edge[i][j] = 0;
	}

	//输入图的信息
	for (int k = 0; k < g->edgeNumber; k++) {
		int i, j;
		printf("请输入有连通的两个顶点的编号，即(vi,vj)的i和j，用空格隔开:");
		scanf("%d%d", &i, &j);
		g->edge[i][j] = 1;    //（i，j）和(j，i)指的是一条边
		g->edge[j][i] = 1;
	}

	//输出图的信息
	printf("Your graph matrix is :\n");
	for (int i = 0; i < g->vertexNumber; i++) {
		for (int j = 0; j < g->vertexNumber; j++) {
			printf("%d\t", g->edge[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	GraphMatrix *gm;
	gm = (GraphMatrix *)malloc(sizeof(GraphMatrix));
	CreateGraphMatrix(gm);

	system("pause");
	return 0;
}
/*==================================完结 分割线==================================*/



