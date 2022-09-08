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
    int top;  // 栈顶指针
} SqStack;
