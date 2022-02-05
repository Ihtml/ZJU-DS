#include "stdio.h"
#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */

int F[100]; /* 斐波那契数列 */

/* 无哨兵顺序查找，a为数组，n为要查找的数组个数，key为要查找的关键字 */
int Sequential_Search(int* a, int n, int key) {
    int i;
    for (i = 1; i <= n; i++) {
        if (a[i] == key)
            return i;
    }
    return 0;
}
/* 有哨兵顺序查找 */
int Sequential_Search2(int* a, int n, int key) {
    int i;
    a[0] = key;
    i = n;
    while (a[i] != key) {
        i--;
    }
    return i;
}

int Binary_Search(int *a, int n, int key){
    int low, high, mid;
    low = 1;
    high = n;
    while (low<=high) {
        mid = (low + high)/2;
        if (key < a[mid])
            high = mid-1;
        else if (key > mid)
            low = mid +1;   
        else
            return mid;
    }
    return 0;
}