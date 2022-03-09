#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAX_LENGTH_INSERT_SORT 7 /* 用于快速排序时判断是否选用插入排序阙值 */

typedef int Status;

#define MAXSIZE 10000 /* 用于要排序数组个数最大值，可根据需要修改 */
typedef struct {
    int r[MAXSIZE + 1]; /* 用于存储要排序数组，r[0]用作哨兵或临时变量 */
    int length; /* 用于记录顺序表的长度 */
} SqList;

/* 交换L中数组r的下标为i和j的值 */
void swap(SqList* L, int i, int j) {
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

void print(SqList L) {
    int i;
    for (i = 1; i < L.length; i++)
        printf("%d,", L.r[i]);
    printf("%d", L.r[i]);
    printf("\n");
}

/* 对顺序表L作交换排序（冒泡排序初级版） */
void BubbleSort0(SqList* L) {
    int i, j;
    for (i = 1; i < L->length; i++) {
        for (j = i + 1; j <= L->length; j++) {
            if (L->r[i] > L->r[j]) {
                swap(L, i, j); /* 交换L->r[i]与L->r[j]的值 */
            }
        }
    }
}

/* 对顺序表L作冒泡排序 */
void BubbleSort(SqList* L) {
    int i, j;
    for (i = 1; i < L->length; i++) {
        for (j = L->length - 1; j >= i; j--) /* 注意j是从后往前循环 */
        {
            if (L->r[j] > L->r[j + 1]) /* 若前者大于后者（注意这里与上一算法的差异）*/
            {
                swap(L, j, j + 1); /* 交换L->r[j]与L->r[j+1]的值 */
            }
        }
    }
}

/* 对顺序表L作改进冒泡算法 */
void BubbleSort2(SqList* L) {
    int i, j;
    Status flag = TRUE; /* flag用来作为标记 */
    for (i = 1; i < L->length && flag; i++) /* 若flag为true说明有过数据交换，否则停止循环 */
    {
        flag = FALSE; /* 初始为False */
        for (j = L->length - 1; j >= i; j--) { /* 循环结束后flag为false说明已从小到大排好序 */
            if (L->r[j] > L->r[j + 1]) {
                swap(L, j, j + 1); /* 交换L->r[j]与L->r[j+1]的值 */
                flag = TRUE;       /* 如果有数据交换，则flag为true */
            }
        }
    }
}

/* 对顺序表L作简单选择排序 */
void SelectSort(SqList* L) {
    int i, j, min;
    for (i = 1; i < L->length; i++) {
        min = i; /* 将当前下标定义为最小值下标 */
        for (j = i + 1; j <= L->length; j++) /* 循环之后的数据 */
        {
            if (L->r[min] > L->r[j]) /* 如果有小于当前最小值的关键字 */
                min = j;             /* 将此关键字的下标赋值给min */
        }
        if (i != min) /* 若min不等于i，说明找到最小值，交换 */
            swap(L, i, min); /* 交换L->r[i]与L->r[min]的值 */
    }
}

/* 对顺序表L作直接插入排序 */
void InsertSort(SqList* L) {
    int i, j;
    for (i = 2; i <= L->length; i++) {
        if (L->r[i] < L->r[i - 1]) /* 需将L->r[i]插入有序子表 */
        {
            L->r[0] = L->r[i]; /* 设置哨兵 */
            for (j = i - 1; L->r[j] > L->r[0]; j--)
                L->r[j + 1] = L->r[j]; /* 记录后移 */
            L->r[j + 1] = L->r[0];     /* 插入到正确位置 */
        }
    }
}

/* 对顺序表L作希尔排序 */
void ShellSort(SqList* L) {
    int i, j, k = 0;
    int increment = L->length;
    do {
        increment = increment / 3 + 1; /* 增量序列 */
        for (i = increment + 1; i <= L->length; i++) {
            if (L->r[i] < L->r[i - increment]) /*  需将L->r[i]插入有序增量子表 */
            {
                L->r[0] = L->r[i]; /*  暂存在L->r[0] */
                for (j = i - increment; j > 0 && L->r[0] < L->r[j]; j -= increment)
                    L->r[j + increment] = L->r[j]; /*  记录后移，查找插入位置 */
                L->r[j + increment] = L->r[0]; /*  插入 */
            }
        }
        printf("第%d趟排序结果: ", ++k);
        print(*L);
    } while (increment > 1);
}