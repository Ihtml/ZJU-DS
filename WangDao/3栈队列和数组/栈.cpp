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

// 初始化
void InitStack(SqStack &S){
    S.top=-1;
}
// 判栈空
bool StackEmpty(SqStack S){
    if (S.top == -1)  // 栈空
        return true;
    else   // 不空
        return false;
}
