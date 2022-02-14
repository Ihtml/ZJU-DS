#include "stdio.h"
#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */

/* 二叉树的二叉链表结点结构定义 */
typedef struct BiTNode /* 结点结构 */
{
    int data;                        /* 结点数据 */
    int bf;                          /*  结点的平衡因子 */
    struct BiTNode *lchild, *rchild; /* 左右孩子指针 */
} BiTNode, *BiTree;

/* 对以p为根的二叉排序树作右旋处理， */
/* 处理之后p指向新的树根结点，即旋转处理之前的左子树的根结点 */
void R_Rotate(BiTree* P) {
    BiTree L;
    L = (*P)->lchild;         /*  L指向P的左子树根结点 */
    (*P)->lchild = L->rchild; /*  L的右子树挂接为P的左子树 */
    L->rchild = (*P);
    *P = L; /*  P指向新的根结点 */
}
