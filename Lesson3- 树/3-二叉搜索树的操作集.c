// 二叉树的增删查操作
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}

BinTree Insert(BinTree BST, ElementType X) {
  if (!BST) { // 原树为空，生成并返回一个节点的二叉树
    BST = malloc(sizeof(struct TNode));
    BST->Data = X;
    BST->Left = BST->Right = NULL;
  } else { // 查找插入的位置
    if (X < BST->Data) {
      BST->Left = Insert(BST->Left, X);
    } else if (X > BST->Data) {
      BST->Right = Insert(BST->Right, X);
    } // 如果X已有不用再插入
  }
  return BST;
}
BinTree Delete(BinTree BST, ElementType X) {
  if (!BST) {
    printf("Not Found\n");
  } else if (X < BST->Data) {
    BST->Left = Delete(BST->Left, X);
  } else if (X > BST->Data) {
    BST->Right = Delete(BST->Right, X);
  } else {
    Position Tmp;
    if (BST->Left && BST->Right) {  // 被删除的元素有两个节点
      // 在右子树中找到最小元素填充删除节点
      Tmp = FindMin(BST->Right);
      BST->Data = Tmp->Data;
      BST->Right = Delete(BST->Right, Tmp->Data);
    } else {  // 被删除的元素只有一个或没有节点
      Tmp = BST;
      if (!BST->Left) {  // 有右节点或无子节点
        BST = BST->Right;
      } else {
        BST = BST->Left;
      }
      free(Tmp);
    }
  }
  return BST;
}

// 二叉搜索树的查找，查找效率取决于树的高度
Position Find(BinTree BST, ElementType X) {
  while (BST) {
    if (X < BST->Data) {
      BST = BST->Left;
    } else if (X > BST->Data) {
      BST = BST->Right;
    } else {
      return BST;
    }
  }
  return NULL;
}
Position FindMin(BinTree BST) {
  // 最小元素一定在树的最左分支的端节点上
  if (!BST) {
    return NULL;
  } else if (!BST->Left) { 
    return BST;
  } else {
    return FindMin(BST->Left);
  }
}
Position FindMax(BinTree BST) {
  // 最大元素一定是在树的最右分枝的端结点上
  if (!BST) {
    return NULL;
  } else if (!BST->Right) {
    return BST;
  } else {
    return FindMax(BST->Right);
  }
}