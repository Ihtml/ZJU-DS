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

const int MaxSize = 255;
typedef struct {
    char ch[MaxSize];  // 每个分量存储一个字符
    int length;        //  串的实际长度
} SString;

// 堆分配存储表示
typedef struct {
    char* ch;    // 按串长分配存储区 ch指向串的基地址
    int length;  // 串的长度
} HString;
