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

int Partition2(int A[], int low, int high) {
    int rand_index = low + rand() % (high - low + 1);  // 随机生成枢轴的下标
    swap(A[rand_index], A[low]);  //  将枢轴值交换到第一个元素
    int pivot = A[low];
    int i = low;  // 使A[low...i]中所有元素小于pivot, 初始为空表
    for (int j = low + 1; j < high; j++) {
        if (A[j] < pivot) {
            swap(A[++i], A[j]);
        }
    }
    swap(A[i], A[low]);
    return i;
}

//  每个元素都是不同整数型元素的顺序线性表，把奇数移到偶数前边
void move(int A[], int len) {
    // 基于快速排序的划分思想，对奇偶进行一次划分
    int i = 0, j = len - 1;  // i表示左边元素的下标 j表示右边元素的下标
    while (i < j) {
        while (i < j && A[i] % 2 != 0)  // 从前往后找到一个偶数元素
            i++;
        while (i < j && A[j] % 2 != 0)  // 从后往前找到一个奇数元素
            j--;
        if (i < j) {
            swap(A[i], A[j]);
        }
        i++;
        j--;
    }
}

// 选择排序
void SelectSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min])
                min = j;
        }
        if (min != i)
            swap(A[i], A[min]);
    }
}

// 建立大根堆
void BuildMaxHeap(int A[], int len) {
    for (int i = len / 2; i > 0; i--) {  // 从i=[n/2]~1 反复调整堆
        HeadAdjust(A, i, len);
    }
}
void HeadAdjust(int A[], int k, int len) {
    // 将元素k为根的子树进行调整
    A[0] = A[k];  // A[0]暂存子树的根结点
    for (int i = 2 * k; i <= len; i = i * 2) {
        if (i < len && A[i] < A[i + 1]) {
            i++;  // 取key较大的子结点的下标
        }
        if (A[0] >= A[i]) {
            break;  //筛选结束
        } else {
            A[k] = A[i];  // 将A[i]调整到双亲结点上
            k = i;        // 修改k值，以便继续向下筛选
        }
    }
    A[k] = A[0];  // 被筛选结点的值放入最终位置
}

void HeapSort(int A[], int len) {
    BuildMaxHeap(A, len);            // 初始建堆
    for (int i = len; i > 1; i--) {  // n-1躺交换和建堆过程
        swap(A[i], A[1]);            // 和堆底元素交换
        HeadAdjust(A, i, i - 1);  // 调整 把剩余的i-1个元素整理成堆
    }
}

bool IsMinHeap(int A[], int len) {
    if (len % 2 == 0) {             // len为偶数 有一个单分支结点
        if (A[len / 2] > A[len]) {  // 判断单分支结点
            return false;
        }
        for (int i = len / 2 - 1; i >= 1; i--) {  // 判断双分支结点
            if (A[i] > A[2 * i] || A[i] > A[2 * i + 1]) {
                return false;
            }
        }
    } else {                            // len为奇数时 没有单分支结点
        for (int i = 0; i >= 1; i--) {  // 判断所有双分支结点
            if (A[i] > A[2 * i] || A[i] > A[2 * i + 1]) {
                return false;
            }
        }
    }
    return true;
}

void MergeSort(int A[], int low, int high){
    if (low < high)
    {
        int mid = (low+high)/2;
        MergeSort(A, low, mid);
        MergeSort(A, mid+1, high);
        Merge(A, low, mid, high);
    }
}
const int N = 1000;
int *B = (int *)malloc((N+1)*sizeof(int));  // 辅助数组
void Merge(int A[], int low, int mid, int high){
    // 将A的两段A[low..mid]和A[mid...high]各自有序，将它们合并成一个有序表
}
