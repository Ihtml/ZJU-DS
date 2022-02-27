#include "stdio.h"
#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* 存储空间初始分配量 */

#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12 /* 定义散列表长为数组的长度 */
#define NULLKEY -32768

typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */

typedef struct {
    int* elem; /* 数据元素存储基址，动态分配数组 */
    int count; /*  当前数据元素个数 */
} HashTable;

int m = 0; /* 散列表表长，全局变量 */

/* 初始化散列表 */
Status InitHashTable(HashTable* H) {
    int i;
    m = HASHSIZE;
    H->count = m;
    H->elem = (int*)malloc(m * sizeof(int));
    for (i = 0; i < m; i++)
        H->elem[i] = NULLKEY;
    return OK;
}
