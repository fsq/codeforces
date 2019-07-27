#include "stdc++.h"

int main() {
  LL n, k;
  cin >> n >> k;

  if (k * (k-1) < n) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  int i = 1, x = 1, cnt = 0;
  while (true) {
    FOR(t, k) {
      int y = x + i;
      if (y > k) y -= k;
      cout << x++ << ' ' << y << endl;
      if (++cnt == n) return 0;
    }
    x = 1; 
    ++i;
  }
  return 0;
}