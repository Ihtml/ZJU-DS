// 对于输入的各种插入序列，判断它们是否能生成一样的二叉搜索树。
// input：
// 4 2
// 3 1 4 2
// 3 4 1 2
// 3 2 4 1
// 2 1
// 2 1
// 1 2
// 0
// outpt:
// Yes
// No
// No
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode *Tree;
struct TreeNode {
  int v;
  Tree Left, Right;
  int flag;
};
int check(Tree T, int V) {
  if (T->flag) {
    if (V < T->v) {
      return check(T->Left, V);
    } else if(V > T->v) {
      return check(T->Right, V);
    } else {
      return 0;
    }
  } else {
    if (V == T->v) {
      T->flag = 1;
      return 1;
    } else {
      return 0;
    }
  }
}
int judge(Tree T, int N) {
  int V, diff = 0;
  scanf("%d", &V);
  if (V != T->v) {
    diff = 1;
  } else {
    T->flag = 1;
  }
  for (int i = 1; i < N; i++) {
    scanf("%d", &V);
    if ((!diff) && (!check(T, V))) {
      diff = 1;
    }
  }
  if (diff) {return 0;} 
  else {return 1;}
}
Tree newNode(int V) {
  Tree T = (Tree)malloc(sizeof(struct TreeNode));
  T->flag = 0;
  T->v = V;
  T->Left = T->Right = NULL;
  return T;
}
Tree insert(Tree T, int V) {
  if (!T) {
    T = newNode(V);
  } else {
    if (V > T->v) {
      T->Right = insert(T->Right, V);
    } else {
      T->Left = insert(T->Left, V);
    }
  }
  return T;
}
Tree MakeTree(int N) {
  Tree T;
  int V;
  scanf("%d", &V);
  T = newNode(V);
  for (int i = 1; i < N; i++) {
    scanf("%d", &V);
    T = insert(T, V);
  }
  return T;
}
void ResetT(Tree T) {
  if (T->Left) {ResetT(T->Left);}
  if (T->Right) {ResetT(T->Right);}
  T->flag = 0;
}
void FreeTree(Tree T) {
  if (T->Left) {FreeTree(T->Left);}
  if (T->Right) {FreeTree(T->Right);}
  free(T);
}
int main() {
  int N, L;
  Tree T;
  scanf("%d", &N);
  while (N) {
    scanf("%d", &L);
    T = MakeTree(N);
    for (int i = 0; i < L; i++) {
      if (judge(T, N)) {printf("Yes\n");} 
      else {printf("No\n");}
      ResetT(T);
    }
    FreeTree(T);
    scanf("%d", &N);
  }
  return 0;
}