#include "stdc++.h"

int main() {
  int n;
  cin >> n;
  VLL a(n);
  LL ans = 0, left = 0;
  FOR(i, n) {
    cin >> a[i];
    LL t = min(left, a[i]/2);
    ans += t;
    left -= t;
    a[i] -= t * 2;

    ans += a[i] / 3;
    a[i] %= 3;

    left += a[i];
  }
  cout << ans << endl;
  return 0;
}