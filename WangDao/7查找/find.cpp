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
typedef struct find {  // 查找表的数据结构
    int* elem;  // 元素存储空间基址，建表时按实际长度分配，0号单元留空
    int TableLen;
} SSTable;
int Search_Seq(SSTable ST, int key) {
    ST.elem[0] = key;  // 哨兵
    int i;
    for (i = ST.TableLen; ST.elem[i] != key; --i)
        ;
    return i;
}

int Binary_Search(SSTable L, int key) {
    int low = 0, high = L.TableLen - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L.elem[mid] == key) {
            return mid;
        } else if (L.elem[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

// 二叉排序树非递归查找
// BSTNode* BST_Search(BiTree T, int key) {
//     while (T != NULL && key != T->data) {
//         if (key <= T->data) {
//             T = T->lchild;
//         } else {
//             T = T->rchild;
//         }
//     }
//     return T;
// }

// 二叉树插入操作
// int BST_Insert(BiTree& T, int k) {
//     if (T == NULL) {
//         T = (BiTree)malloc(sizeof(BSTNode));
//         T->data = k;
//         T->lchild = T->rchild = NULL;
//         return 1;
//     } else if (k == T->data) {
//         return 0;
//     } else if (k < T->data) {
//         return BST_Insert(T->lchild, k);
//     } else {
//         return BST_Insert(T->rchild, k);
//     }
// }

// int predt = INT_MIN;  // 保存当前结点中序前驱的值
// 初值为-🈚️穷 int JudgeBST(BiTree bt) {
//     int b1, b2;
//     if (bt == NULL) {  // 空树
//         return 1;
//     } else {
//         b1 = JudgeBST(bt->lchild);
//         if (b1 = 0 || predt >= bt->data) {
//             return 0; // 若左子树返回0或前驱大于等于当前结点 则不是二叉排序树
//         }
//         predt = bt->data; // 保存当前结点关键字
//         b2 = JudgeBST(bt->rchild);
//         return b2; // 返回右子树的结果
//     }
// }

// 查找结点所用的次数就是该结点在二叉排序树中的层数
// int level(BiTree bt, BSTNode* p) {
//     int n = 0;
//     BiTree t = bt;
//     if (bt != NULL) {
//         n++;
//         while (t->data != p->data) {
//             if (p->data < t->data) {
//                 t = t->lchild;
//             } else {
//                 t = t->rchild;
//             }
//             n++;
//         }
//     }
//     return n;
// }

// 找最小结点，即最左下结点
// int MinKey(BSTNode* bt) {
//     while (bt->lchild != NULL) {
//         bt = bt->lchild;
//     }
//     return bt->data;
// }
// int MaxKey(BSTNode* bt) {
//     while (bt->rchild != NULL) {
//         bt = bt->rchild;
//     }
//     return bt->data;
// }

// 从大到小输出二叉排序树中所有值不小于k的关键字
void OutPut(BSTNode* bt, int k) {
    if (bt == NULL)
        return;
    if (bt->rchild != NULL) {
        OutPut(bt->rchild, k);
    }
    if (bt->data >= k) {
        cout << bt->data;
    }
    if (bt->lchild != NULL) {
        OutPut(bt->lchild, k);
    }
}