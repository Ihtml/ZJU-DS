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
