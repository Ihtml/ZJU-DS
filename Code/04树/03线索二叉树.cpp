#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status; /* Status是函数的类型,其值是函数结果状态代码,如OK等 */
typedef char TElemType;
typedef enum { Link, Thread } PointerTag; /* Link==0表示指向左右孩子指针, */
/* Thread==1表示指向前驱或后继的线索 */
typedef struct BiThrNode /* 二叉线索存储结点结构 */
{
    TElemType data;                    /* 结点数据 */
    struct BiThrNode *lchild, *rchild; /* 左右孩子指针 */
    PointerTag LTag;
    PointerTag RTag; /* 左右标志 */
} BiThrNode, *BiThrTree;

TElemType Nil = '#'; /* 字符型以空格符为空 */

Status visit(TElemType e) {
    printf("%c ", e);
    return OK;
}

/* 按前序输入二叉线索树中结点的值,构造二叉线索树T */
/* 0(整型)/空格(字符型)表示空结点 */
Status CreateBiThrTree(BiThrTree* T) {
    TElemType h;
    scanf("%c", &h);

    if (h == Nil)
        *T = NULL;
    else {
        *T = (BiThrTree)malloc(sizeof(BiThrNode));
        if (!*T)
            exit(OVERFLOW);
        (*T)->data = h;                 /* 生成根结点(前序) */
        CreateBiThrTree(&(*T)->lchild); /* 递归构造左子树 */
        if ((*T)->lchild)               /* 有左孩子 */
            (*T)->LTag = Link;
        CreateBiThrTree(&(*T)->rchild); /* 递归构造右子树 */
        if ((*T)->rchild)               /* 有右孩子 */
            (*T)->RTag = Link;
    }
    return OK;
}
