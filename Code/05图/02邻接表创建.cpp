#include "stdio.h"
#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* 最大顶点数,应由用户定义 */

typedef int Status; /* Status是函数的类型,其值是函数结果状态代码,如OK等 */
typedef char VertexType; /* 顶点类型应由用户定义 */
typedef int EdgeType;    /* 边上的权值类型应由用户定义 */

typedef struct EdgeNode /* 边表结点  */
{
    int adjvex;    /* 邻接点域,存储该顶点对应的下标 */
    EdgeType info; /* 用于存储权值,对于非网图可以不需要 */
    struct EdgeNode* next; /* 链域,指向下一个邻接点 */
} EdgeNode;

typedef struct VertexNode /* 顶点表结点 */
{
    VertexType data;     /* 顶点域,存储顶点信息 */
    EdgeNode* firstedge; /* 边表头指针 */
} VertexNode, AdjList[MAXVEX];