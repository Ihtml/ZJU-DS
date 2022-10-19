#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <vector>
using namespace std;
const int MAXVertexNum = 100;  //  顶点数目最大值
typedef char VertexType; //  顶点的数据类型
typedef int EdgeType;  //  带权图中边上权值的数据类型
typedef struct {
    VertexType Vex[MAXVertexNum];   // 顶点表
    EdgeType Edge[MAXVertexNum][MAXVertexNum];   // 邻接矩阵 边表
    int vexnum, arcnum;  // 图的当前顶点数和弧数
}MGraph;