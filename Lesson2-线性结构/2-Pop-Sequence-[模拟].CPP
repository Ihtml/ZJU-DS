#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
  int m, n, k;
  scanf("%d %d %d", &m, &n, &k);
  for (int i = 0; i < k; i++) {
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &v[i]);
    }
    stack<int> s;
    int flag = 0, cur = 1;
    for (int i = 1; i <= n; i++) {
      s.push(i);
      if (s.size() > m) {
        break;
      }
      while (!s.empty() && s.top() == v[cur]) {
        s.pop();
        cur++;
      }
    }
    if (cur == n + 1) {
      flag = 1;
    }
    if (flag) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}