#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> pre, in, post, value;
void postorder(int root, int start, int end) {
  if (start > end) return;
  int i = start;
  while (i < end && in[i] != root) i++;
  postorder(root + 1, start, i - 1);
  postorder(root + i - start + 1, i + 1, end);
  // post.push_back(pre[root]);
  post.push_back(in[i]);
}
int main() {
  int n, t, key = 0;
  cin >> n;
  char s[5];
  stack<int> st;
  while (~scanf("%s", s)) {
    if (strlen(s) == 4) {
      cin >> t;
      value.push_back(t);
      pre.push_back(key);
      st.push(key++);
    } else {
      in.push_back(st.top());
      st.pop();
    }
  }
  postorder(0, 0, n - 1);
  printf("%d", value[post[0]]);
  for (int i = 1; i < n; i++) {
    printf(" %d", value[post[i]]);
  }
  return 0;
}