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
typedef struct LNode {  // 定义单链表结点类型
    struct LNode *next;  // 数据域
    int data;  // 指针域
}LNode, *LinkList;