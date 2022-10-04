#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <vector>
using namespace std;

typedef struct BiTNode {
    int data;                         // 数据域
    struct BiTNode *lchild, *rchild;  // 左、右孩子指针
} BiTNode, *BiTree;

// 先序遍历
void PreOrder(BiTree T) {
    if (T != NULL) {
        // visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

// 非递归的中序遍历
// void PreOrder2(BiTree T) {
//     InitStack(S);
//     BiTree p = T;
//     while (p || !IsEmpty(S)) {
//         if (p) {
//             visit(p);
//             Push(S, p);
//             p = p->lchild;
//         } else {
//             Pop(S, p);
//             p = p->rchild;
//         }
//     }
// }

// 中序遍历
void InOrder(BiTree T) {
    if (T != NULL) {
        InOrder(T->lchild);
        // visit(T);
        InOrder(T->rchild);
    }
}

// 非递归的中序遍历
// void InOrder2(BiTree T) {
//     InitStack(S);
//     BiTree p = T;
//     while (p || !IsEmpty(S)) {
//         if (p) {
//             Push(S, p);
//             p = p->lchild;
//         } else {
//             Pop(S, p);
//             visit(p);
//             p = p->rchild;
//         }
//     }
// }

void PostOrder(BiTree T) {
    if (T != NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        // visit(T);
    }
}
