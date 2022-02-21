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

/*  在p->node[1..keynum].key中查找i,使得p->node[i].key≤K＜p->node[i+1].key */
int Search(BTree p, int K) {
    int i = 0, j;
    for (j = 1; j <= p->keynum; j++)
        if (p->node[j].key <= K)
            i = j;
    return i;
}

/*  在m阶B树T上查找关键字K，返回结果(pt,i,tag)。若查找成功，则特征值 */
/*  tag=1，指针pt所指结点中第i个关键字等于K；否则特征值tag=0，等于K的  */
/*  关键字应插入在指针Pt所指结点中第i和第i+1个关键字之间。 */
Result SearchBTree(BTree T, int K) {
    BTree p = T, q = NULL; /*  初始化，p指向待查结点，q指向p的双亲  */
    Status found = FALSE;
    int i = 0;
    Result r;
    while (p && !found) {
        i = Search(p, K); /*  p->node[i].key≤K<p->node[i+1].key  */
        if (i > 0 && p->node[i].key == K) /*  找到待查关键字 */
            found = TRUE;
        else {
            q = p;
            p = p->node[i].ptr;
        }
    }
    r.i = i;
    if (found) /*  查找成功  */
    {
        r.pt = p;
        r.tag = 1;
    } else /*   查找不成功，返回K的插入位置信息 */
    {
        r.pt = q;
        r.tag = 0;
    }
    return r;
}