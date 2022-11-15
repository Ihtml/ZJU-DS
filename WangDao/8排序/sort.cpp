#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <vector>

using namespace std;

void InsertSort(int A[], int n) {
    int i, j;
    for (i = 2; i < n; i++) {  // 依次将A[2]~A[n]插入前面已排序序列
        if (A[i] < A[i - 1]) {
            A[0] = A[i];  // 复制为哨兵，A[0]不存放元素
            for (j = i - 1; A[0] < A[j]; --j) {  // 从后往前查待插入位置
                A[j + 1] = A[j];                 // 向后挪位
            }
            A[j + 1] = A[0];  // 复制到插入位置
        }
    }
}

// 最坏时间复杂度O(n^2)
void ShellSort(int A[], int n) {
    // A[0]只是暂存单元，不是哨兵，当j<=0时，插入位置已到
    for (int dk = n / 2; dk >= 1; dk = dk / 2) {
        int i, j;
        for (i = dk + 1; i <= n; i++) {
            if (A[i] < A[i - dk]) {  // A[i]插入有序增量子表
                A[0] = A[i];         // 暂存在A[0]
                for (j = i - dk; j > 0 && A[0] < A[j]; j = j - dk) {
                    A[j + dk] = A[j];  // 记录后移,查找插入位置
                }
                A[j + dk] = A[0];  // 插入
            }
        }
    }
}

// 冒泡排序
void BubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool flag = false;
        for (int j = n - 1; j > i; j--) {
            if (A[j - 1] > A[j]) {
                swap(A[j - 1], A[j]);
                flag = true;
            }
        }
        if (flag == false) {  // 遍历后没有发生交换 说明表已经有序
            return;
        }
    }
}

void QuickSort(int A[], int low, int high) {
    if (low < high) {
        int pivotpos = Partition(A, low, high);
        QuickSort(A, low, pivotpos - 1);
        QuickSort(A, pivotpos + 1, high);
    }
}
int Partition(int A[], int low, int high) {
    int pivot = A[low];
    while (low < high) {
        while (low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}