#include "stdc++.h"

int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  VLL a(n), f(n);
  FOR(i, n) cin >> a[i];
  partial_sum(ALL(a), f.begin());
  LL ans = k * f.back();  
  f.pop_back();
  sort(ALL(f));
  ans -= accumulate(f.begin(), f.begin()+k-1, 0ll);
  cout << ans << endl;
  return 0;
}