#include "stdio.h"
#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* 存储空间初始分配量 */

#define m 3   /*  B树的阶，暂设为3 */
#define N 17  /*  数据元素个数 */
#define MAX 5 /*  字符串最大长度+1  */

typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */

typedef struct BTNode {
    int keynum;            /*  结点中关键字个数，即结点的大小 */
    struct BTNode* parent; /*  指向双亲结点 */
    struct Node            /*  结点向量类型 */
    {
        int key;            /*  关键字向量 */
        struct BTNode* ptr; /*  子树指针向量 */
        int recptr;         /*  记录指针向量 */
    } node[m + 1];          /*  key,recptr的0号单元未用 */
} BTNode, *BTree;           /*  B树结点和B树的类型 */

typedef struct {
    BTNode* pt; /*  指向找到的结点 */
    int i;      /*  1..m，在结点中的关键字序号 */
    int tag;    /*  1:查找成功，O:查找失败 */
} Result;       /*  B树的查找结果类型 */