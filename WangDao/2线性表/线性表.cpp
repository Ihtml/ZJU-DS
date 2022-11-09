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
    int* data;            // 指示动态分配数组的指针
    int MaxSize, length;  // 数组最大容量和当前个数
};

// C语言的初始动态分配语句
// struct SeqList SeqList1;
// SeqList1.data = (int*)malloc(sizeof(int) * InitSize);

// C++初始动态分配语句
// SeqList SeqList1;
// SeqList1.data = new int[InitSize];

// 顺序表插入
bool ListInsert(SqList& L, int i, int e) {
    if (i < 1 || i > L.length + 1)  // 判断i的范围是否有效
        return false;
    if (L.length >= MaxSize)  // 当前存储空间已满，不能插入
        return false;
    for (int j = L.length; j >= i; j--)  // 将第i个元素及之后的元素后移
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;  // 在位置i处放入e
    L.length++;         // 线性表长度加一
    return true;
}

bool ListDelete(SqList& L, int i, int& e) {
    if (i < 1 || i > L.length)  // 判断i的范围是否有效
        return false;
    e = L.data[i - 1];  // 将被删除的元素赋给e
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];  // 将第i个位置后的元素前移
    }
    L.length--;  // 线性表长度减1
    return true;
}

// 按值查找（顺序查找）
int locateElem(SqList L, int e) {
    int i;
    for (i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

// 搜索整个顺序表 查找最小值并用value返回并删除 空出的位置用最后一个元素填补
bool Del_Min(SqList& L, int& value) {
    if (L.length == 0) {
        return false;
    }
    value = L.data[0];
    int pos = 0;
    for (int i = 1; i < L.length; i++) {
        if (L.data[i] < value) {
            value = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length - 1];
    L.length--;
    return true;
}

// 删除顺序表中所有值为x的数据元素
void del_all_x_1(SqList& L, int x) {
    int k = 0, i;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] != x) {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}

// 反转顺序表
void Reverse(SqList& L) {
    int temp;
    for (int i = 0; i < L.length / 2; i++) {
        temp = L.data[i];  // 交换L.data[i]与L.data[L.length-i-1]
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
}
int main() {
    return 0;
}