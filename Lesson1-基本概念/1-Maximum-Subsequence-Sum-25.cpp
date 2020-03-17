#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int flag = 1, tleft = 0, ThisSum = 0, MaxSum = -1, left = 0, right = n - 1;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    if (v[i] >= 0) {
      flag = 0;
    }
    ThisSum += v[i];
    if (ThisSum < 0) {
      ThisSum = 0;
      tleft = i + 1;
    } else if (ThisSum > MaxSum) {
      MaxSum = ThisSum;
      left = tleft;
      right = i;
    }
  }
  if (MaxSum < 0)
    MaxSum = 0;
  printf("%d %d %d", MaxSum, flag ? v[0] : v[left], flag ? v[n - 1] : v[right]);
  return 0;
}