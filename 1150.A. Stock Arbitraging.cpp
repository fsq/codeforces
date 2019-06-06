#include "stdc++.h"

int main() {
  int n, m, r, x;
  cin >> n >> m >> r;
  int a = INT_MAX, b = INT_MIN;
  FOR(i, n) {
    cin >> x;
    a = min(a, x);
  }
  FOR(i, m) {
    cin >> x;
    b = max(b, x);
  }
  int t = r / a;
  r = max(r, r - t*a + t*b);
  cout << r << endl;
  return 0;
}