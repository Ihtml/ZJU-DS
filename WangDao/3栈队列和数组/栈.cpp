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

// 栈的顺序存储类型
typedef struct {
    int data[MaxSize];  // 存放栈中元素
    int top;  // 栈顶指针  初始时设置s.top=-1; 栈顶元素：s.data[s.top]
} SqStack;

typedef struct Linknode {
    int data;               // 数据域
    struct Linknode* next;  // 指针域
} * LiStack;                // 栈类型定义

// 初始化
void InitStack(SqStack& S) {
    S.top = -1;
}
// 判栈空
bool StackEmpty(SqStack S) {
    if (S.top == -1)  // 栈空
        return true;
    else  // 不空
        return false;
}
// 进栈
bool Push(SqStack& S, int x) {
    if (S.top == MaxSize - 1)  // 栈满 报错
        return false;
    S.data[++S.top] = x;  // 指针先加1
    return true;
}
// 出栈
bool Pop(SqStack& S, int& x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top--];  // 先出栈 指针再减一
    return true;
}

// 读栈顶元素
bool GetTop(SqStack S, int& x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top];
}