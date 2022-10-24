#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <vector>

using namespace std;
const int MAXVertexNum = 100;  //  顶点数目最大值
const int infinity = INT_MAX;
typedef char VertexType;  //  顶点的数据类型
typedef int EdgeType;     //  带权图中边上权值的数据类型
typedef struct {
    VertexType Vex[MAXVertexNum];               // 顶点表
    EdgeType Edge[MAXVertexNum][MAXVertexNum];  // 邻接矩阵 边表
    int vexnum, arcnum;  // 图的当前顶点数和弧数
} MGraph;

typedef struct ArcNode {  // 边表结点
    int adjvex;           // 该弧所指向的顶点位置
    struct ArcNode* next;
} ArcNode;

typedef struct VNode {  // 顶点表结点
    VertexType data;    // 顶点信息
    ArcNode* first;     //  指向第一条依附该顶点的弧的指针
} VNode, AdjList[MAXVertexNum];
typedef struct {
    AdjList vertices;    // 邻接表
    int vexnum, arcnum;  // 图的顶点数和弧数
} ALGraph;               // ALGraph是以邻接表存储的图类型

queue<int> Q;
bool visited[MAXVertexNum];
int d[MAXVertexNum];
void BFSTraverse(MGraph G) {
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) {
            BFS(G, i);
        }
    }
}
void BFS(MGraph G, int v) {
    cout << v;
    visited[v] = true;
    Q.push(v);
    while (Q.size() != 0) {
        v = Q.front();
        Q.pop();
        // for (w = FirstNeighbor(G, v); w >= 0; w = NextNeibor(G, v, w)) {
        //     if (!visited[w]) {
        //         cout << w;
        //         visited[w] = true;
        //         Q.push(w);
        //     }
        // }
    }
}
void BFS_Min_Distance(MGraph G, int u) {
    for (int i = 0; i < G.vexnum; i++) {
        d[i] = infinity;
    }
    visited[u] = true;
    d[u] = 0;
    Q.push(u);

    while (Q.size() != 0) {
        u = Q.front();
        Q.pop();
        // for (w = FirstNeighbor(G, v); w >= 0; w = NextNeibor(G, v, w)) {
        //     if (!visited[w]) {
        //         cout << w;
        //         visited[w] = true;
        //         d[w]=d[u]+1;
        //         Q.push(w);
        //     }
        // }
    }
}