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
    struct BiTNode *lchild, *rchild; /* 左右孩子指针 */
} BiTNode, *BiTree;

/* 递归查找二叉排序树T中是否存在key, */
/* 指针f指向T的双亲，其初始调用值为NULL */
/* 若查找成功，则指针p指向该数据元素结点，并返回TRUE */
/* 否则指针p指向查找路径上访问的最后一个结点并返回FALSE */
Status SearchBST(BiTree T, int key, BiTree f, BiTree* p) {
    if (!T) /*  查找不成功 */
    {
        *p = f;
        return FALSE;
    } else if (key == T->data) /*  查找成功 */
    {
        *p = T;
        return TRUE;
    } else if (key < T->data)
        return SearchBST(T->lchild, key, T, p); /*  在左子树中继续查找 */
    else
        return SearchBST(T->rchild, key, T, p); /*  在右子树中继续查找 */
}