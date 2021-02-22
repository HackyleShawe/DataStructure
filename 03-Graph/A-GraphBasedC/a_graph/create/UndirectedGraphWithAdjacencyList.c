#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

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
    EdgeNode *t=NULL; //辅助指针
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
        e->next = g->list[i].firstedge;
        g->list[i].firstedge = e;

        e = (EdgeNode*)malloc(sizeof(EdgeNode)); //因为是无向图，一条边对应都是两个顶点，所以在一次循环中针对i和j分别进行插入；
        e->adjvex = i;
        e->next = g->list[j].firstedge;
        g->list[j].firstedge = e;
    }
}

void ShowALGraph(GraphAdjList *g)
{
    int i;
    printf("\n遍历邻接表：\n");
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

int main()
{
    GraphAdjList *g;
    g = (GraphAdjList*)malloc(sizeof(GraphAdjList));
    CreateALGraph(g);
    ShowALGraph(g);
    system("pause");
    return 0;
}

// 输入：
// 4 5
// V0 V1 V2 V3
// 0 1
// 0 2
// 0 3
// 1 2
// 2 3

// 输出：
// 遍历邻接表：
// V0：->3->2->1->NULL
// V1：->2->0->NULL
// V2：->3->1->0->NULL
// V3：->2->0->NULL
