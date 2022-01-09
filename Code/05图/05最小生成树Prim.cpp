#include "stdio.h"
#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 65535

typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */

typedef struct {
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
} MGraph;

void CreateMGraph(MGraph* G) /* 构件图 */
{
    int i, j;

    /* printf("请输入边数和顶点数:"); */
    G->numEdges = 15;
    G->numVertexes = 9;

    for (i = 0; i < G->numVertexes; i++) /* 初始化图 */
    {
        for (j = 0; j < G->numVertexes; j++) {
            if (i == j)
                G->arc[i][j] = 0;
            else
                G->arc[i][j] = G->arc[j][i] = INFINITY;
        }
    }

    G->arc[0][1] = 10;
    G->arc[0][5] = 11;
    G->arc[1][2] = 18;
    G->arc[1][8] = 12;
    G->arc[1][6] = 16;
    G->arc[2][8] = 8;
    G->arc[2][3] = 22;
    G->arc[3][8] = 21;
    G->arc[3][6] = 24;
    G->arc[3][7] = 16;
    G->arc[3][4] = 20;
    G->arc[4][7] = 7;
    G->arc[4][5] = 26;
    G->arc[5][6] = 17;
    G->arc[6][7] = 19;

    for (i = 0; i < G->numVertexes; i++) {
        for (j = i; j < G->numVertexes; j++) {
            G->arc[j][i] = G->arc[i][j];
        }
    }
}
