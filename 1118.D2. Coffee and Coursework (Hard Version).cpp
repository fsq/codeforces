#include "stdc++.h"

int main() {
  int n, m;
  cin >> n >> m;
  VI a(n+1);
  LL tot = 0;
  REP(i, 1, n) {
    cin >> a[i];
    tot += a[i];
  }
  if (tot < m) {
    cout << -1 << '\n';
    return 0;
  }
  if (tot == m) {
    cout << n << '\n';
    return 0;
  }
  sort(a.begin()+1, a.end(), greater<int>());
  int l=1, r=n-1;
  while (l < r) {
    int mid = (l + r) >> 1;
    LL s = 0, st = 0;

    for (int i=0, j=1; j<=n; ++i) {
      for (int l=0; l<mid && j+l<=n; ++l)
        s += max(a[j+l]-i, 0);
      j += mid;
    }
    
    if (s >= m) 
      r = mid;
    else 
      l = mid + 1;
  }
  cout << l << endl;
  return 0;
}