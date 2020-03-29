#include <iostream>
#include <map>
using namespace std;
int main() {
  map<int, int, greater<int> > mp1, mp2, mpa, mpb;
  int n, m, a, b, c, d;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    mp1[b] = a;
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    mp2[b] = a;
  }
  for (auto it = mp1.begin(); it != mp1.end(); it++) {
    b = it->first;
    a = it->second;
    mpa[b] += a;
    for (auto pi = mp2.begin(); pi != mp2.end(); pi++) {
      d = pi->first;
      c = pi->second;
      mpb[b + d] += a * c;
    }
  }
  for (auto it = mp2.begin(); it != mp2.end(); it++) {
    b = it->first;
    a = it->second;
    mpa[b] += a;
  }
  int flaga = 0, flagb = 0;
  for (auto it = mpa.begin(); it != mpa.end(); it++)
  {
    if (it->second != 0)
    {
      flaga = 1;break;
    }
  }
  for (auto it = mpb.begin(); it != mpb.end(); it++)
  {
    if (it->second != 0)
    {
      flagb = 1;break;
    }
  }
  if (flagb == 0)
  {
    printf("%d %d", 0, 0);
  }else{
    for (auto it = mpb.begin(); it != mpb.end() && it->second != 0; it++) {
      if (it != mpb.begin()) {
        cout << " ";
      }
      cout << it->second << " " << it->first;
    }
  }
  cout << endl;
  if (flaga == 0)
  {
    printf("%d %d", 0, 0);
  }else{
    for (auto it = mpa.begin(); it != mpa.end() && it->second != 0; it++) {
      if (it != mpa.begin()) {
        cout << " ";
      }
      cout << it->second << " " << it->first;
    }
  }
  return 0;
}