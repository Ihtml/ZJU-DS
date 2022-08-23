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
// 线性表的顺序存储类型
struct SqList {
    int data[MaxSize];
    int length;
};
// struct SqList list1; // C语言写法
SqList list1;  // C++不用写struct

// 动态分配
const int InitSize = 100;
struct SeqList {
    int *data;  // 指示动态分配数组的指针
    int MaxSize, length;  // 数组最大容量和当前个数
};

// C语言的初始动态分配语句
// struct SeqList SeqList1;
// SeqList1.data = (int*)malloc(sizeof(int) * InitSize);

// C++初始动态分配语句
// SeqList SeqList1;
// SeqList1.data = new int[InitSize];

// 顺序表插入 
bool ListInsert(SqList &L, int i, int e){
    if(i<1 || i>L.length+1)  // 判断i的范围是否有效
        return false;
    if (L.length >= MaxSize) // 当前存储空间已满，不能插入
        return false;
    for (int j = L.length; j>=i; j--)  // 将第i个元素及之后的元素后移
        L.data[j]=L.data[j-1];
    L.data[i-1]=e;  // 在位置i处放入e
    L.length++;  // 线性表长度加一
    return true;
}

int main() {
    return 0;
}