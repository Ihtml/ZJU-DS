#include "stdio.h"
#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */
#define OVERFLOW 0

typedef int Status;
typedef int QElemType; /* QElemType类型根据实际情况而定，这里假设为int */

typedef struct QNode /* 结点结构 */
{
    QElemType data;
    struct QNode* next;
} QNode, *QueuePtr;

typedef struct /* 队列的链表结构 */
{
    QueuePtr front, rear; /* 队头、队尾指针 */
} LinkQueue;

Status visit(QElemType c) {
    printf("%d ", c);
    return OK;
}

/* 构造一个空队列Q */
Status InitQueue(LinkQueue* Q) {
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q->front)
        exit(OVERFLOW);  // exit 函数强制使函数停止函数，釆用整数实参，要使用
                         // ，必须包含 <cstdlib> 头文件
    Q->front->next = NULL;
    return OK;
}

/* 销毁队列Q */
Status DestroyQueue(LinkQueue* Q) {
    while (Q->front) {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return OK;
}

/* 将Q清为空队列 */
Status ClearQueue(LinkQueue* Q){
    QueuePtr p, q;
    Q->rear = Q->front;
    p = Q->front->next;
    while (p)
    {
        q=p;
        p=p->next;
        free(q);
    }
    return OK;
}