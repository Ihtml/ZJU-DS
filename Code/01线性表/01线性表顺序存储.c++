
#include "stdio.h"

#include "math.h"
#include "stdlib.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType; /* ElemType类型根据实际情况而定，这里假设为int */

Status visit(ElemType c) {
    printf("%d ", c);
    return OK;
}

typedef struct {
    ElemType data[MAXSIZE]; /* 数组，存储数据元素 */
    int length;             /* 线性表当前长度 */
} SqList;

/* 初始化顺序线性表 */
Status InitList(SqList* L) {
    L->length = 0;
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE
 */
Status ListEmpty(SqList L) {
    if (L.length == 0)
        return TRUE;
    else
        return FALSE;
}

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(SqList* L) {
    L->length = 0;
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(SqList L) {
    return L.length;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始
 */
Status GetElem(SqList L, int i, ElemType* e) {
    if (L.length == 0 || i < 1 || i > L.length)
        return ERROR;
    *e = L.data[i - 1];

    return OK;
}
