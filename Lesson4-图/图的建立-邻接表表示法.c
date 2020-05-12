#include <stdio.h>
#define MaxVertexNum 100  // 最大顶点数
typedef char DataType;    // 顶点储存的数据类型设为字符型
typedef int Vertex;       // 顶点下标表示顶点，为整形
typedef int WeightType;   // 边的权重设为整形

// 邻接点定义
typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode {     
  Vertex AdjV;        // 邻接点下标
  WeightType Weight;  // 边权重
  PtrToAdjVNode Next;
};
// 顶点表头结点定义
typedef struct Vnode {      
  PtrToAdjVNode FirstEdge;  // 指向第一个边
  DataType Data;            // 顶点数据
} AdjList[MaxVertexNum];    // 邻接表类型
// 图节点的定义
typedef struct GNode* PtrToGNode;
struct GNode {        
  int Nv;   // 顶点数
  int Ne;   // 边数
  AdjList G;    // 邻接表
};
typedef PtrToGNode LGraph;
// 边的定义
typedef struct ENode* PtrToENode;
struct ENode {
  Vertex V1, V2;     /* 有向边<V1, V2> */
  WeightType Weight; /* 权重 */
};
typedef PtrToENode Edge;
// 初始化有VertexNum个顶点的图
LGraph CreateGraph(int VertexNum) {
  Vertex V, M;
  LGraph Graph;
  Graph = (LGraph)malloc(sizeof(struct GNode));
  Graph->Nv = VertexNum;
  Graph->Nv = 0;
  for (int i = 0; i < VertexNum; i++) {
    Graph->G[i].FirstEdge = NULL;
  }
}
// 插入边
void InsertEdge(LGraph Graph, Edge E) {
  // 插入边<v1, v2>
  PtrToAdjVNode NewNode;
  // 为v2建立新的邻接点
  NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
  NewNode->AdjV = E->V2;
  NewNode->Weight = E->Weight;
  // 把v2插入v1的表头
  NewNode->Next = Graph->G[E->V1].FirstEdge;
  Graph->G[E->V1].FirstEdge = NewNode;

  // 如果是无向图，插入边<v2, v1>
  NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
  NewNode->AdjV = E->V1;
  NewNode->Weight = E->Weight;
  NewNode->Next = Graph->G[E->V2].FirstEdge;
  Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph() {
  LGraph Graph;
  Edge E;
  Vertex V;
  int Nv, i;

  scanf("%d", &Nv);        /* 读入顶点个数 */
  Graph = CreateGraph(Nv); /* 初始化有Nv个顶点但没有边的图 */

  scanf("%d", &(Graph->Ne));                /* 读入边数 */
  if (Graph->Ne != 0) {                     /* 如果有边 */
    E = (Edge)malloc(sizeof(struct ENode)); /* 建立边结点 */
    /* 读入边，格式为"起点 终点 权重"，插入邻接矩阵 */
    for (i = 0; i < Graph->Ne; i++) {
      scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
      /* 注意：如果权重不是整型，Weight的读入格式要改 */
      InsertEdge(Graph, E);
    }
  }

  /* 如果顶点有数据的话，读入数据 */
  for (V = 0; V < Graph->Nv; V++)
    scanf(" %c", &(Graph->G[V].Data));

  return Graph;
}