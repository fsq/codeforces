#include "stdc++.h"

int main() {
  int n, m, x;
  cin >> n >> m;

  VI a(2), b(2);
  FOR(i, n) {
    cin >> x;
    ++a[x&1];
  }
  FOR(i, m) {
    cin >> x;
    ++b[x&1];
  }

  cout << (min(a[1], b[0])+min(a[0], b[1])) << endl;
  return 0;
}