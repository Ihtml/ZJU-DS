#include "stdio.h"
#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 9 /* 存储空间初始分配量 */
#define MAXEDGE 15
#define MAXVEX 9
#define INFINITY 65535

typedef int Status; /* Status是函数的类型,其值是函数结果状态代码,如OK等 */
typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */

typedef char VertexType; /* 顶点类型应由用户定义 */
typedef int EdgeType;    /* 边上的权值类型应由用户定义 */

/* 邻接矩阵结构 */
typedef struct {
    char vexs[MAXVEX];      /* 顶点表 */
    int arc[MAXVEX][MAXVEX]; /* 邻接矩阵,可看作边表 */
    int numVertexes, numEdges;    /* 图中当前的顶点数和边数 */
} MGraph;

/* 邻接表结构****************** */
typedef struct EdgeNode /* 边表结点 */
{
    int adjvex; /* 邻接点域,存储该顶点对应的下标 */
    int weight; /* 用于存储权值,对于非网图可以不需要 */
    struct EdgeNode* next; /* 链域,指向下一个邻接点 */
} EdgeNode;

typedef struct VertexNode /* 顶点表结点 */
{
    int in;              /* 顶点入度 */
    char data;           /* 顶点域,存储顶点信息 */
    EdgeNode* firstedge; /* 边表头指针 */
} VertexNode, AdjList[MAXVEX];

typedef struct {
    AdjList adjList;
    int numVertexes, numEdges; /* 图中当前顶点数和边数 */
} graphAdjList, *GraphAdjList;
/* **************************** */

/* 用到的队列结构与函数********************************** */
/* 循环队列的顺序存储结构 */
typedef struct {
    int data[MAXSIZE];
    int front; /* 头指针 */
    int rear; /* 尾指针,若队列不空,指向队列尾元素的下一个位置 */
} Queue;

/* 初始化一个空队列Q */
Status InitQueue(Queue* Q) {
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

/* 若队列Q为空队列,则返回TRUE,否则返回FALSE */
Status QueueEmpty(Queue Q) {
    if (Q.front == Q.rear) /* 队列空的标志 */
        return TRUE;
    else
        return FALSE;
}

/* 若队列未满,则插入元素e为Q新的队尾元素 */
Status EnQueue(Queue* Q, int e) {
    if ((Q->rear + 1) % MAXSIZE == Q->front) /* 队列满的判断 */
        return ERROR;
    Q->data[Q->rear] = e;              /* 将元素e赋值给队尾 */
    Q->rear = (Q->rear + 1) % MAXSIZE; /* rear指针向后移一位置, */
                                       /* 若到最后则转到数组头部 */
    return OK;
}

/* 若队列不空,则删除Q中队头元素,用e返回其值 */
Status DeQueue(Queue* Q, int* e) {
    if (Q->front == Q->rear) /* 队列空的判断 */
        return ERROR;
    *e = Q->data[Q->front];              /* 将队头元素赋值给e */
    Q->front = (Q->front + 1) % MAXSIZE; /* front指针向后移一位置, */
                                         /* 若到最后则转到数组头部 */
    return OK;
}
/* ****************************************************** */