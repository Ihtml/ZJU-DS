#include <limits.h>  // 定义最大整数INT_MAX的头文件
#include <math.h>    // abs()函数所在的头文件
#define xIsMin(x, y, z) (((x) <= (y)) && ((x) <= (z)))  // 定义辅助计算的宏
void Reverse(int A[], int n) {
    int i, t;
    for (i = 0; i < n / 2; i++) {
        t = A[i];
        A[i] = A[n - i - 1];
        A[n - i - 1] = t;
    }
}