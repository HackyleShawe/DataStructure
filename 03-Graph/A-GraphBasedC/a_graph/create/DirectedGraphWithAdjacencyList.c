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
