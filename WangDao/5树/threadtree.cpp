#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <vector>
using namespace std;

typedef struct ThreadNode {
    int data;                            // 数据域
    struct ThreadNode *lchild, *rchild;  // 左、右孩子指针
    int ltag, rtag;
} ThreadNode, *ThreadTree;
