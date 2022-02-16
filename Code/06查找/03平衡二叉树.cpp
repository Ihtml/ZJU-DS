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

/* 对以P为根的二叉排序树作左旋处理， */
/* 处理之后P指向新的树根结点，即旋转处理之前的右子树的根结点0  */
void L_Rotate(BiTree* P) {
    BiTree R;
    R = (*P)->rchild;         /*  R指向P的右子树根结点 */
    (*P)->rchild = R->lchild; /* R的左子树挂接为P的右子树 */
    R->lchild = (*P);
    *P = R; /*  P指向新的根结点 */
}

#define LH +1 /*  左高 */
#define EH 0  /*  等高 */
#define RH -1 /*  右高 */

/*  对以指针T所指结点为根的二叉树作左平衡旋转处理 */
/*  本算法结束时，指针T指向新的根结点 */
void LeftBalance(BiTree* T) {
    BiTree L, Lr;
    L = (*T)->lchild; /*  L指向T的左子树根结点 */
    switch (L->bf) { /*  检查T的左子树的平衡度，并作相应平衡处理 */
        case LH: /*  新结点插入在T的左孩子的左子树上，要作单右旋处理 */
            (*T)->bf = L->bf = EH;
            R_Rotate(T);
            break;
        case RH: /*  新结点插入在T的左孩子的右子树上，要作双旋处理 */
            Lr = L->rchild;   /*  Lr指向T的左孩子的右子树根 */
            switch (Lr->bf) { /*  修改T及其左孩子的平衡因子 */
                case LH:
                    (*T)->bf = RH;
                    L->bf = EH;
                    break;
                case EH:
                    (*T)->bf = L->bf = EH;
                    break;
                case RH:
                    (*T)->bf = EH;
                    L->bf = LH;
                    break;
            }
            Lr->bf = EH;
            L_Rotate(&(*T)->lchild); /*  对T的左子树作左旋平衡处理 */
            R_Rotate(T);             /*  对T作右旋平衡处理 */
    }
}