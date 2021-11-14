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

/* 链栈结构 */
typedef struct StackNode {
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct {
    LinkStackPtr top;
    int count;
} LinkStack;

Status visit(SElemType c) {
    printf("%d ", c);
    return OK;
}

/*  构造一个空栈S */
Status InitStack(LinkStack* S) {
    S->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if (!S->top)
        return ERROR;
    S->top = NULL;
    S->count = 0;
    return OK;
}

/* 把S置为空栈 */
Status ClearStack(LinkStack* S) {
    LinkStackPtr p, q;
    p = S->top;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    S->count = 0;
    return OK;
}

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status StackEmpty(LinkStack S) {
    if (S.count == 0)
        return TRUE;
    else
        return FALSE;
}
