#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <vector>
using namespace std;

typedef struct ThreadNode {
    int data;                            // 数据域
    struct ThreadNode *lchild, *rchild;  // 左、右孩子指针
    int ltag, rtag;
} ThreadNode, *ThreadTree;

// 通过中序遍历对二叉树线索化
void InThread(ThreadTree& p, ThreadTree& pre) {
    if (p != NULL) {
        InThread(p->lchild, pre);  // 递归线索化左子树
        if (p->lchild == NULL) {   // 左子树为空，建立前驱线索
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;  // 建立前驱结点的后继线索
            pre->rtag = 1;
        }
        pre = p;  // 标识当前结点为刚刚访问过的结点
        InThread(p->rchild, pre);  // 递归 线索化右子树
    }
}