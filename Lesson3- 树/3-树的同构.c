// 给定两棵树T1和T2。如果T1可以通过"若干次左右孩子互换"就变成T2，则称两棵树是“同构”的。
#include <stdio.h>
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1
struct TreeNode {
  ElementType Element;
  Tree Left;
  Tree Right;
} T1[MaxTree], T2[MaxTree];

int N, Root = Null, check[MaxTree];
Tree BuildTree(struct TreeNode T[]) {
  char cl, cr;
  scanf("%d\n", &N);
  if (N) {
    for (int i = 0; i < N; i++) {
      check[i] = 0;
    }
    for (int i = 0; i < N; i++) {
      scanf("%c %c %c\n", &T[i].Element, &cl, &cr);  // 注意吸收每一行的回车符
      if (cl == '-') {
        T[i].Left = Null;
      } else {
        T[i].Left = cl - '0';
        check[T[i].Left] = 1;
      }
      if (cr == '-') {
        T[i].Right = Null;
      } else {
        T[i].Right = cr - '0';
        check[T[i].Right] = 1;
      }
    }
    for (int i = 0; i < N; i++) {
      if (!check[i]) {  // 没有其他元素指向的节点，就是根节点
        Root = i;
        break;
      }
    }
  }
  return Root;
}
// 判别两棵树重构
int Isomorphic(Tree R1, Tree R2) {
  if (R1 == Null && R2 == Null) {  // 都为空
    return 1;
  }
  if ((R1 == Null && R2 != Null) || (R1 != Null && R2 == Null)) {  // 只一个为空
    return 0;
  }
  if (T1[R1].Element != T2[R2].Element) {  // 根节点元素不相等
    return 0;
  }
  if ((T1[R1].Left == Null) && (T2[R2].Left == Null)) {  // 都没有左树
    return Isomorphic(T1[R1].Right, T2[R2].Right);
  }
  if ((T1[R1].Left != Null) && (T2[R2].Left != Null) &&
      (T1[T1[R1].Left].Element ==
       T2[T2[R2].Left].Element)) {  // 不需要交换左右进行比较
    return Isomorphic(T1[R1].Left, T2[R2].Left) &&
           Isomorphic(T1[R1].Right, T2[R2].Right);
  } else  // 需要交换左右进行比较
  {
    return Isomorphic(T1[R1].Left, T2[R2].Right) &&
           Isomorphic(T1[R1].Right, T2[R2].Left);
  }
}

int main() {
  Tree R1, R2;  // 根节点
  R1 = BuildTree(T1);
  R2 = BuildTree(T2);

  if (Isomorphic(R1, R2)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
