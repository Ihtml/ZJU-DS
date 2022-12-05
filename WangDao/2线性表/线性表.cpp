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
    int k = 0, i;  // k记录值不等于x的元素个数
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] != x) {
            L.data[k] = L.data[i];
            k++;  // 不等于x的元素个数加一
        }
    }
    L.length = k;  // 顺序表的长度等于k
}
// 删除顺序表中所有值为x的数据元素
void del_all_x_2(SqList& L, int x) {
    int k = 0, i;  // k记录值等于x的元素个数
    while (i < L.length) {
        if (L.data[i] == x)
            k++;
        else
            L.data[i - k] = L.data[i];  // 当前元素前移k个位置
        i++;
    }
    L.length = L.length - k;  // 顺序表L的长度递减
}

// 删除有序顺表L中在给定值s与t之间的所有元素
bool del_s2t(SqList& L, int s, int t) {
    int i, j;
    if (s >= t || L.length == 0) {
        return false;
    }
    for (i = 0; i < L.length && L.data[i] < s; i++) {
        // 寻找值大于等于s的第一个元素
    }
    if (i >= L.length) {
        return false;
    }
    for (j = i; j < L.length && L.data[j] <= t; j++) {
        // 寻找值大于t的第一个元素
    }
    while (j < L.length) {
        L.data[i] = L.data[j];  // 前移 填补被删除元素位置
        i++;
        j++;
    }
    L.length = i;
    return true;
}

// 删除无序顺序表L中在给定值s与t之间的所有元素
bool del_s2t_2(SqList& L, int s, int t) {
    int i, k;
    if (s >= t || L.length == 0) {
        return false;
    }
    for (i = 0; i < L.length; i++) {
        if (L.data[i] >= s && L.data[i] <= t) {
            k++;
        } else {
            L.data[i - k] = L.data[i];  // 当前元素前移k个位置
        }
    }
    L.length = L.length - k;
    return true;
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

// 有序表去重
bool Delete_Same(SqList& L) {
    if (L.length == 0) {
        return false;
    }
    int i, j;  // i存储第一个不相同元素 j为工作指针
    for (i = 0, j = 1; j < L.length; j++) {
        if (L.data[i] != L.data[j]) {  // 查找下一个与上一个元素值不同的元素
            i++;
            L.data[i] = L.data[j];  // 找到后，将元素前移
        }
    }
    L.length = i + 1;
    return true;
}

// 将有序顺序表A与B合并为一个新的有序顺序表C
bool Merge(SqList A, SqList B, SqList& C) {
    if (A.length + B.length > C.maxSize) {
        return false;
    }
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length) {
        if (A.data[i] <= B.data[j]) {
            C.data[k++] = A.data[i++];
        } else {
            C.data[k++] = B.data[j++];
        }
    }
    while (i < A.length) {
        C.data[k++] = A.data[i++];
    }
    while (j < B.length) {
        C.data[k++] = B.data[j++];
    }
    C.length = k;
    return true;
}

// 顺序表位置互换
// 先将数组A[m+n]中的全部元素(a1,a2,...am,b1,b2,...bn)原地逆置为(bm bm-1, b1,
// am, am-1,...a1)
// 再对前n个元素和后m个元素分别使用逆置算法，即可得到(b1,b2,..bn,a1,a2,...am)
void Reverse(int A[], int left, int righ, int arraySize) {
    if (left > right || right >= arraySize) {
        return;
    }
    int mid = (left + right) / 2;
    for (int i = 0; i < mid - left; i++) {
        int t = A[left + i];
        A[left + i] = A[right - i];
        A[right - i] = t;
    }
}
void Exchange(int A[], int m, int n, int arraySize) {
    // 数组A[m+n]中
    // 从0到m-1存放顺序表(a1,a2,..am)从m到m+n-1存放顺序表(b1,b2,...bn)
    // 算法将这两个表的位置互换
    Reverse(A, 0, m + n - 1, arraySize);
    Reverse(A, n - 1, arraySize);
    Reverse(A, n, m + n - 1, arraySize);
}

void SearchExchangeInsert(int A[], int x) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {  // 折半查找
        mid = (low + high) / 2;
        if (A[mid] == x)
            break;
        else if (A[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (A[mid] == x && mid != n - 1) { 
        int t = A[mid];
        A[mid] = A[mid + 1];
        A[mid + 1] = t;
    }
    if (low > high) {  // 查找失败 插入数据元素
        for (int i = n - 1; i > high; i--) {
            A[i + 1] = A[i];
        }
        A[i + 1] = x;
    }
}
int main() {
    return 0;
}