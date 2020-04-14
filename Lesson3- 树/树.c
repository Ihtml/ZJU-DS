#include <stdio.h>
typedef int ElementType; /* ElemType类型根据实际情况而定，这里假设为int */

// 二叉树的链表结构
typedef struct TNode* Position;
typedef Position BinTree;  // 二叉树类型
struct TNode {             // 树节点定义
  ElementType Data;
  BinTree Left;   // 指向左树
  BinTree Right;  // 指向右树
};

// 先序遍历 先访问根节点，再对左边递归，再对右边递归
void PreOrderTraversal(BinTree BT) {
  if (BT) {
    printf("%d", BT->Data);
    PreOrderTraversal(BT->Left);
    PreOrderTraversal(BT->Right);
  }
}
// 中序遍历 先递归访问左子树，再访问根节点，再遍历右子树
void InOrderTraversal(BinTree BT) {
  if (BT) {
    PreOrderTraversal(BT->Left);
    printf("%d", BT->Data);
    PreOrderTraversal(BT->Right);
  }
}
// 后序遍历 先递归遍历左边，再遍历右边，最后根节点
void PostOrderTraversal(BinTree BT) {
  if (BT) {
    PreOrderTraversal(BT->Left);
    PreOrderTraversal(BT->Right);
    printf("%d", BT->Data);
  }
}
