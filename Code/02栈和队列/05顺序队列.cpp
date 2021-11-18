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
typedef int QElemType; /* QElemType类型根据实际情况而定，这里假设为int */

/* 循环队列的顺序存储结构 */
typedef struct {
    QElemType data[MAXSIZE];
    int front; /* 头指针 */
    int rear; /* 尾指针，若队列不空，指向队列尾元素的下一个位置 */
} SqQueue;

Status visit(QElemType c) {
    printf("%d ", c);
    return OK;
}

/* 初始化一个空队列Q */
Status InitQueue(SqQueue* Q) {
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

/* 将Q清为空队列 */
Status ClearQueue(SqQueue* Q) {
    Q->front = Q->rear = 0;
    return OK;
}

/* 若队列Q为空队列,则返回TRUE,否则返回FALSE */
Status QueueEmpty(SqQueue Q) {
    if (Q.front == Q.rear) /* 队列空的标志 */
        return TRUE;
    else
        return FALSE;
}

/* 返回Q的元素个数，也就是队列的当前长度 */
int QueueLength(SqQueue Q) {
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}