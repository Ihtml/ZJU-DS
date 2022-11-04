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