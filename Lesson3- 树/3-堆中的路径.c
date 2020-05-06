// 将一系列给定数字插入一个初始为空的小顶堆H[]。随后对任意给定的下标i，打印从H[i] 到根结点的路径。
// 5 3
// 46 23 26 24 10
// 5 4 3

#include <stdio.h>
#define MaxN 1001
#define MinData -10001
    int H[MaxN],
    size;
void Create() {
  size = 0;
  H[0] = MinData;
}
void Insert(int X) {
  int i = ++size;
  for (; X < H[i / 2]; i /= 2) {
    H[i] = H[i / 2];
  }
  H[i] = X;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  Create();
  for (int i = 0; i < n; i++) {
    int X;
    scanf("%d", &X);
    Insert(X);
  }
  for (int i = 0; i < m; i++) {
    int j;
    scanf("%d", &j);
    printf("%d", H[j]);
    while (j > 1) {
      j /= 2;
      printf(" %d", H[j]);
    }
    printf("\n");
  }
  return 0;
}