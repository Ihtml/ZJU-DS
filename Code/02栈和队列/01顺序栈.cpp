#include "stdio.h"
#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 1
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;
typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */

/* 顺序栈结构 */
typedef struct {
    SElemType data[MAXSIZE];
    int top; /* 用于栈顶指针 */
} SqStack;

Status visit(SElemType c) {
    printf("%d ", c);
    return OK;
}

/*  构造一个空栈S */
Status InitStack(SqStack *S) {
    // S.data=(SElemType *)malloc(MAXSIZE*sizeof(SElemType)); 
    S->top = -1;
    return OK;
}

/* 把S置为空栈 */
Status ClearStack(SqStack* S) {
    S->top = -1;
    return OK;
}

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status StackEmpty(SqStack S) {
    if (S.top == -1)
        return TRUE;
    else
        return FALSE;
}

/* 返回S的元素个数，即栈的长度 */
int StackLength(SqStack S) {
    return S.top + 1;
}

