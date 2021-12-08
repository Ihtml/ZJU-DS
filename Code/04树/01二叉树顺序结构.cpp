#include "stdio.h"
#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100       /* 存储空间初始分配量 */
#define MAX_TREE_SIZE 100 /* 二叉树的最大结点数 */

typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int TElemType; /* 树结点的数据类型，目前暂定为整型 */
typedef TElemType SqBiTree[MAX_TREE_SIZE]; /* 0号单元存储根结点  */

typedef struct {
    int level, order; /* 结点的层,本层序号(按满二叉树计算) */
} Position;

TElemType Nil = 0; /*  设整型以0为空 */

Status visit(TElemType c) {
    printf("%d ", c);
    return OK;
}

/* 构造空二叉树T。因为T是固定数组，不会改变，故不需要& */
Status InitBiTree(SqBiTree T) {
    int i;
    for (i = 0; i < MAX_TREE_SIZE; i++)
        T[i] = Nil; /* 初值为空 */
    return OK;
}

/* 按层序次序输入二叉树中结点的值(字符型或整型), 构造顺序存储的二叉树T */
Status CreateBiTree(SqBiTree T) {
    int i = 0;
    printf("请按层序输入结点的值(整型)，0表示空结点，输999结束。结点数≤%d:\n", MAX_TREE_SIZE);
    while (i < 10) {
        T[i] = i + 1;

        if (i != 0 && T[(i + 1) / 2 - 1] == Nil && T[i] != Nil) /* 此结点(不空)无双亲且不是根 */
        {
            printf("出现无双亲的非根结点%d\n", T[i]);
            exit(ERROR);
        }
        i++;
    }
    while (i < MAX_TREE_SIZE) {
        T[i] = Nil; /* 将空赋值给T的后面的结点 */
        i++;
    }
    return OK;
}

#define ClearBiTree InitBiTree /* 在顺序存储结构中，两函数完全一样 */

/* 初始条件: 二叉树T存在 */
/* 操作结果: 若T为空二叉树,则返回TRUE,否则FALSE */
Status BiTreeEmpty(SqBiTree T) {
    if (T[0] == Nil) /* 根结点为空,则树空 */
        return TRUE;
    else
        return FALSE;
}

/* 初始条件: 二叉树T存在。操作结果: 返回T的深度 */
int BiTreeDepth(SqBiTree T) {
    int i, j = -1;
    for (i = MAX_TREE_SIZE - 1; i >= 0; i--) /* 找到最后一个结点 */
        if (T[i] != Nil)
            break;
    i++;
    do
        j++;
    while (i >= powl(2, j)); /* 计算2的j次幂。 */
    return j;
}

/* 初始条件: 二叉树T存在 */
/* 操作结果:  当T不空,用e返回T的根,返回OK;否则返回ERROR,e无定义 */
Status Root(SqBiTree T, TElemType* e) {
    if (BiTreeEmpty(T)) /* T空 */
        return ERROR;
    else {
        *e = T[0];
        return OK;
    }
}