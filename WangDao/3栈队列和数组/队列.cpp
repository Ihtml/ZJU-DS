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
    int front, rear;    // 队头指针和队尾指针
} SqQueue;

// 循环队列
void InitQueue(SqQueue &Q){
    Q.rear = Q.front = 0;  // 初始化队首、队尾指针
}
// 循环队列判队空
bool isEmpty(SqQueue Q){
    if (Q.rear==Q.front)
        return true;
    else
        return false;
}