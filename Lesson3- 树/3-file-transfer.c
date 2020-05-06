#include <stdio.h>
typedef int ElementType;
typedef int SetName;  // 默认用根节点下标作为集合名称
#define MaxN 10001
typedef ElementType SetType[MaxN];

SetName Find(SetType S, ElementType X) {
  // 不使用路径压缩，时间复杂度 O(logN)
  //   for (; S[X] >= 0; X = S[X])
  //     ;
  //   return X;
  // 路径压缩 复杂度<=4
  if (S[X] < 0){ // 找到了集合的根
    return X;
  } else {
      // 先找到根，把根变成X的父结点，再返回根
    return S[X] = Find(S, S[X]);
  }
}
void Union(SetType S, SetName Root1, SetName Root2) {
  // 比树高按秩归并
  //   if (S[Root2] < S[Root1])
  //     S[Root1] = Root2;
  //   else {
  //     if (S[Root1] == S[Root2])
  //       S[Root1]--;
  //     S[Root2] = Root1;
  //   }
  //   比规模按秩归并 最坏复杂度 O(logN)
  if (S[Root2] < S[Root1]) {
    S[Root2] += S[Root1];
    S[Root1] = Root2;
  } else {
    S[Root1] += S[Root2];
    S[Root2] = Root1;
  }
}
void Initialization(SetType S, int n) {
  for (int i = 0; i < n; i++) {
    S[i] = -1;
  }
}
void Input_connection(SetType S) {
  ElementType u, v;
  SetName Root1, Root2;
  scanf("%d %d\n", &u, &v);
  Root1 = Find(S, u - 1);
  Root2 = Find(S, v - 1);
  if (Root1 != Root2) {
    Union(S, Root1, Root2);
  }
}
void Check_connection(SetType S) {
  ElementType u, v;
  SetName Root1, Root2;
  scanf("%d %d\n", &u, &v);
  Root1 = Find(S, u - 1);
  Root2 = Find(S, v - 1);
  if (Root1 == Root2) {
    printf("yes\n");
  } else {
    printf("no\n");
  }
}
void Check_network(SetType S, int n) {
  int ctn = 0;
  for (int i = 0; i < n; i++) {
    if (S[i] < 0) {
      ctn++;
    }
  }
  if (ctn == 1) {
    printf("The network is connected.\n");
  } else {
    printf("There are %d components.\n", ctn);
  }
}
int main() {
  SetType S;
  int n;
  char in;
  scanf("%d\n", &n);
  Initialization(S, n);
  do {
    scanf("%c", &in);
    switch (in) {
      case 'I':
        Input_connection(S);
        break;
      case 'C':
        Check_connection(S);
        break;
      case 'S':
        Check_network(S, n);
        break;
    }
  } while (in != 'S');
  return 0;
}