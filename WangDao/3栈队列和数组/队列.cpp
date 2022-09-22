#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <vector>
using namespace std;

const int MaxSize = 50;
typedef struct {
    int data[MaxSize];  // 存放队列元素
    // 初始状态（队空条件） Q.front==Q.rear==0
    int front, rear;  // 队头指针和队尾指针
} SqQueue;

// 循环队列
void InitQueue(SqQueue& Q) {
    Q.rear = Q.front = 0;  // 初始化队首、队尾指针
}
// 循环队列判队空
bool isEmpty(SqQueue Q) {
    if (Q.rear == Q.front)
        return true;
    else
        return false;
}
// 循环队列入队
bool EnQueue(SqQueue& Q, int x) {
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;  //  队满则报错
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;  // 队尾指针加1取模
    return true;
}
// 循环队列出队
bool DeQueue(SqQueue& Q, int& x) {
    if (Q.rear == Q.front)
        return false;  // 队空报错
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;  // 队头指针加1
    return true;
}

// 队列的链式存储结构
typedef struct LinkNode {  // 链式队列结点
    int data;
    struct LinkNode* next;
} LinkNode;
typedef struct {             // 链式队列
    LinkNode *front, *rear;  // 队列的队头和队尾指针
} LinkQueue;

// 链式队列初始化
void InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));  // 建立头结点
    Q.front->next = NULL;
}

// 判队空
bool IsEmpty(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

// 入队
void EnQueue(LinkQueue& Q, int x) {
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;  // 创建新结点，插入到链尾
    Q.rear->next = s;
    Q.rear = s;
}

// 出队
bool DeQueue(LinkQueue& Q, int& x) {
    if (Q.front = Q.rear)
        return false;  // 空队
    LinkNode* p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;  // 原队列中只有一个结点，删除后变空
    free(p);
    return true;
}