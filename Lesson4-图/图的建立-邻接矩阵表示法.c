#include <stdio.h>
#define MaxVertexNum 100  // 最大顶点数
#define INFINITY 65535    // 设为双字节无符号整数的最大值65535
typedef int Vertex;       // 顶点下标表示顶点，为整形
typedef int WeightType;   // 边的权重设为整形
typedef char DataType;    // 顶点储存的数据类型设为字符型
typedef struct GNode* PtrToGNode;
struct GNode {
  int Nv;  // 顶点数
  int Ne;  // 边树
  WeightType G[MaxVertexNum][MaxVertexNum];
  DataType Data[MaxVertexNum];  // 存顶点的数据
};
typedef PtrToGNode MGraph;  // 以邻接矩阵存储的图类型

typedef int Vertex;  // 用顶点的下标表示顶点，为整型
MGraph CreateGraph(int VertexNum) {  // 创建没有边，只有VertexNum个顶点的空图
  Vertex V, W;
  MGraph Graph;

  Graph = (MGraph)malloc(sizeof(struct GNode));
  Graph->Nv = VertexNum;
  Graph->Ne = 0;

  for (V = 0; V < Graph->Nv; V++)
    for (W = 0; W < Graph->Nv; W++)
      Graph->G[V][W] = 0;  // 如果是有权图设为INFINITY
  return Graph;
}

typedef struct ENode* PtrToGNode;
struct ENode {
  Vertex V1, V2;      // 有向边<V1, V2>
  WeightType Weight;  // 权重
};
typedef PtrToGNode Edge;

void InsertEdge(MGraph Graph, Edge E) {
  // 插入边<V1, V2>
  Graph->G[E->V1][E->V2] = E->Weight;
  // 无向图还要插入边<V2, V1>
  Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph() {
  MGraph Graph;
  Edge E;
  Vertex V;
  int Nv, i;
  scanf("%d", &Nv);           // 读入顶点数
  Graph = CreateGraph(Nv);    // 初始化一个图
  scanf("%d", &(Graph->Ne));  // 读入边数
  if (Graph->Ne != 0) {       // 如果有边
    E = (Edge)malloc(sizeof(struct ENode));  // 临时边的节点
    for (int i = 0; i < Graph->Ne; i++) {
      scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
      InsertEdge(Graph, E);
    }
  }
  // 如果顶点有数据，读入数据
  for (V = 0; V < Graph->Nv; V++) {
    scanf(" %c", &(Graph->Data[V]));
  }
  return Graph;
}
