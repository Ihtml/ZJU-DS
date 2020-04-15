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

// 二叉树遍历的非递归遍历（使用堆栈）：
#define MaxSize 10000
typedef struct SNode* Stack;
struct SNode {
  ElementType Data[MaxSize];
  int Top;
};

// 先序
void PreOrderTraversal(BinTree BT) {
  BinTree T = BT;
  Stack S = CreatStack(MaxSize);
  while (T || !IsEmpty(S)) {
    while (T) {
      printf("%5d", T->Data);
      Push(S, T);
      T = T->Left;
    }
    if (!IsEmpty(S)) {
      T = Pop(S);
      T = T->Right;
    }
  }
}

// 中序
void InorderTraversal(BinTree BT) {
  BinTree T = BT;
  Stack S = CreatStack(MaxSize);
  while (T || !IsEmpty(S)) {
    while (T) {
      Push(S, T);
      T = T->Left;
    }
    if (!IsEmpty(S)) {
      T = Pop(S);
      printf("%5d", T->Data);
      T = T->Right;
    }
  }
}

// 后序
void PostOrderTraversal(BinTree BT) {
  BinTree T = BT, P = NULL;  // P为上一个访问的节点
  Stack S = CreatStack(MaxSize);
  while (T || !IsEmpty(S)) {
    Push(S, T);
    T = T->Left;
  }
  if (!IsEmpty(S)) {
    T = Pop(S);
    if (T->Right == NULL || T->Right == P) {
      // 右节点不存在或右节点已访问，弹出节点
      printf("%5d", T->Data);
      P = T;  // P指向当前被访问的节点
      T = NULL;
    } else {
      Push(T);       // 如果有右节点，该节点再次入栈
      T = T->Right;  // 继续遍历右树
    }
  }
}

// 层次遍历（队列）
struct QNode {
  int rear;
  int front;
  ElementType Data[MaxSize];
};
typedef struct QNode* Queue;
void LevelOrderTraversal(BinTree BT) {
  Queue Q;
  BinTree T;
  if (!BT)
    return;
  Q = CreatQueue(MaxSize);
  AddQ(Q, BT);
  while (!IsEmptyQ(Q)) {
    T = DeleteQ(Q);
    printf("%5d", T->Data);
    if (T->Left) {
      AddQ(Q, T->Left);
    }
    if (T->Right) {
      AddQ(Q, T->Right);
    }
  }
}