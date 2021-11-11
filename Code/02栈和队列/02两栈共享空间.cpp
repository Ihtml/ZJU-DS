#include "stdio.h"
#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;
typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */

/* 两栈共享空间结构 */
typedef struct {
    SElemType data[MAXSIZE];
    int top1; /* 栈1栈顶指针 */
    int top2; /* 栈2栈顶指针 */
} SqDoubleStack;

Status visit(SElemType c) {
    printf("%d ", c);
    return OK;
}

/*  构造一个空栈S */
Status InitStack(SqDoubleStack* S) {
    S->top1 = -1;
    S->top2 = MAXSIZE;
    return OK;
}

/* 把S置为空栈 */
Status ClearStack(SqDoubleStack* S) {
    S->top1 = -1;
    S->top2 = MAXSIZE;
    return OK;
}

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status StackEmpty(SqDoubleStack S) {
    if (S.top1 == -1 && S.top2 == MAXSIZE)
        return TRUE;
    else
        return FALSE;
}
