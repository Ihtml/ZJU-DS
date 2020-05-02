typedef struct AVLNode* Position;
typedef Position AVLTree;
typedef int ElementType; /* ElemType类型根据实际情况而定，这里假设为int */
#define NULL 0
struct AVLNode {   // AVL树类型
  ElementType Data;  // 节点数据
  AVLTree Left;
  AVLTree Right;
  int Height;
};
int Max(int a, int b) {
  return a > b ? a : b;
}
int GetHeight(AVLTree root) {
  if (root == NULL) {
    return 0;
  }
  return Max(GetHeight(root->Left), GetHeight(root->Right)) + 1;
}
AVLTree SingleLeftRotation(AVLTree A) {
  AVLTree B = A->Left;  // 这里A必须有个左子节点B
  A->Left = B->Right;   // A与B做左单旋，更新A与B的高度，返回新的根节点B
  B->Right = A;
  A->Height = GetHeight(A);
  B->Height = GetHeight(B);
  return B;
}
AVLTree SingleRightRotation(AVLTree A) {
  AVLTree B = A->Right; 
  A->Right = B->Left;
  B->Left = A;
  A->Height = GetHeight(A);
  B->Height = GetHeight(B);
  return B;
}
AVLTree DoubleLeftRightRotation(AVLTree A) {
    // 这里A必须有个左子节点B，且B必须有个右子节点C
    // B与C做右单旋，返回C
  A->Left = SingleRightRotation(A->Left); 
    // A与C做左单旋，返回C
  return SingleLeftRotation(A);
}
AVLTree DoubleRightLeftRotation(AVLTree A) {
  A->Right = SingleLeftRotation(A->Right);
  return SingleRightRotation(A);
}
AVLTree Insert(AVLTree T, ElementType X) {
  if (!T) {
    T = (AVLTree)malloc(sizeof(struct AVLNode));
    T->Data = X;
    T->Height = 0;
    T->Left = T->Right = NULL;
  } else if (X < T->Data) {
    T->Left = Insert(T->Left, X);
    if (GetHeight(T->Left) - GetHeight(T->Right) == 2) {
      if (X < T->Left->Data) {
        T = SingleLeftRotation(T);
      } else {
        T = DoubleLeftRightRotation(T);
      }
    }
  } else if (X > T->Data) {
    T->Right = Insert(T->Right, X);
    if (GetHeight(T->Right) - GetHeight(T->Left) == 2) {
      if (X > T->Right->Data) {
        T = SingleRightRotation(T);
      } else {
        T = DoubleRightLeftRotation(T);
      }
    }

  } else {
    // X == T->Data 无须插入
  }
  // 每次都要更新树高
  T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
  return T;
}