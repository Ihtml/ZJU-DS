#include <cstdio>
#include <queue>
struct TreeNode {
  int idx, left, right;
} arr[10];
using namespace std;
queue<int> q;
int flag = 0;
void isLeave(int r) {
  if (r == -1) {
    return;
  }
  q.push(r);
  while (q.size()) {
    int t = q.front();
    q.pop();
    if (arr[t].left == -1 && arr[t].right == -1) {
      if (flag) {
        printf(" ");
      } else {
        flag = 1;
      }
      printf("%d", t);
    }
    if (arr[t].left != -1) {
      q.push(arr[t].left);
    }
    if (arr[t].right != -1) {
      q.push(arr[t].right);
    }
  }
}
int main() {
  int n, r, check[10] = {0};
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    char cl, cr;
    scanf("%c %c\n", &cl, &cr);
    arr[i].idx = i;
    arr[i].left = cl == '-' ? -1 : cl - '0';
    arr[i].right = cr == '-' ? -1 : cr - '0';
    if (arr[i].left != -1) {
      check[arr[i].left] = 1;
    }
    if (arr[i].right != -1) {
      check[arr[i].right] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (check[i] == 0) {
      r = i;
      break;
    }
  }
  isLeave(r);
  return 0;
}
