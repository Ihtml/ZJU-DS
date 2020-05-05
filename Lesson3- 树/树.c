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
      Push(S, T);       // 如果有右节点，该节点再次入栈
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

// 二叉搜索树的查找 查找效率决定于树的高度
Position Find(ElementType X, BinTree BST) {
  while (BST) {
    if (X > BST->Data) {
      BST = BST->Right;
    } else if (X < BST->Data) {
      BST = BST->Left;
    } else {
      return BST;
    }
  }
  return NULL;
}
// 查找最小元素
Position FindMin(BinTree BST) {
  if (!BST) {
    return NULL;
  } else if (!BST->Left) {
    return BST;
  } else {
    return FindMin(BST->Left);
  }
}
// 查找最大元素
Position FindMax(BinTree BST) {
  if (BST) {
    while (BST->Right) {
      BST = BST->Right;
    }
  }
  return BST;
}
//  二插搜索树的插入
BinTree Insert(ElementType X, BinTree BST) {
  if (!BST) { // 原树为空，生成并返回一个节点的二叉树
    BST = malloc(sizeof(struct TNode));
    BST->Data = X;
    BST->Right = NULL;
    BST->Left = NULL;
  } else { // 找要插入的位置
    if (X < BST->Data) {  // 递归插入左子树
      BST->Left = Insert(X, BST->Left);
    } else if (X > BST->Data) { // 递归插入右子树
      BST->Right = Insert(X, BST->Right);
    }
    // 如果 X已经存在，不需要再插入
  }
  return BST;
}
// 二叉搜索树的删除
BinTree Delete(ElementType X, BinTree BST) {
  if (!BST) {
    printf("要删除的元素未找到");
  } else if (BST->Data < X) {
    BST->Right = Delete(X, BST->Right);
  } else if (BST->Data > X) {
    BST->Left = Delete(X, BST->Left);
  } else {
    Position Tmp;
    if (BST->Left && BST->Right) { // 被删除的元素有两个节点
      Tmp = FindMin(BST->Right); // 在右子树中找到最小元素填充删除节点
      BST->Data = Tmp->Data;
      BST->Right = Delete(Tmp->Data, BST->Right); // 在删除节点的右子树中删除最小元素
    } else { // 被删除元素有一个或没有节点
      Tmp = BST;
      if (!BST->Left) { // 有右节点或无子节点
        BST = BST->Right;
      } else if (!BST->Right) { // 有左节点
        BST = BST->Left;
      }
      free(Tmp);
    }
  }
  return BST;
}