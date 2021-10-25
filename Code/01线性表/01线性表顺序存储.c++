
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