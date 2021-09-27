#include <limits.h> // 定义最大整数INT_MAX的头文件
#include <math.h> // abs()函数所在的头文件
#define xIsMin(x,y,z) (((x) <= (y)) && ((x) <= (z))) // 定义辅助计算的宏
int findMinofTrip(int A[], int n, int B[], int m, int C[], int p){
    int i = 0, j=0, k = 0, min = INT_MAX, dist;
    // min用于记录三元组最小距离，赋初值为INT_MAX
    while (i < n && j <m && k < p && min > 0)
    {
        dist = abs(A[i] - B[j]) + abs(B[j] - C[k]) + abs(C[k]-A[i]);
        if (dist < min) min = dist;
        if (xIsMin(A[i], B[j], C[k])) i++;
        else if (xIsMin(B[j], C[k], A[i],)) j++;
        else k++;
    }
    return min;
}
