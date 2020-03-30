#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int first, n, k, ctn = 0;
  int list[100000], data[100000], next[100000];
  cin >> first >> n >> k;
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    scanf("%d %d", &data[t], &next[t]);
  }
  while (first != -1) {
    list[ctn++] = first;
    first = next[first];
  }
  for (int i = 0; i < (ctn - ctn % k); i += k) {
    reverse(begin(list) + i, begin(list) + i + k);
  }
  for (int i = 0; i < ctn - 1; i++) {
    printf("%05d %d %05d\n", list[i], data[list[i]], list[i + 1]);
  }
  printf("%05d %d -1", list[ctn - 1], data[list[ctn - 1]]);
  return 0;
}