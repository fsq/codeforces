#include "stdc++.h"

int main() {
  ios::sync_with_stdio(false);
  int n, x, s = 0;
  VI a(3);
  cin >> n;
  FOR(i, n) {
    cin >> x;
    ++a[x];
    s += x;
  }

  if (!a[1]) {
    FOR(i, a[2]) cout << 2 << ' ';
  } else if (!a[2]) {
    FOR(i, a[1]) cout << 1 << ' ';
  } else {
    cout << 2 << ' ' << 1 << ' ';
    FOR(i, a[2]-1) cout << 2 << ' ';
    FOR(i, a[1]-1) cout << 1 << ' ';
  }
  return 0;

  // below are correct but lousy 

  VI vis(s+1), p;
  REP(x, 2, s) {
    if (!vis[x]) p.PB(x);
    for (int j=0; j<SZ(p) && x*p[j]<=s; ++j) {
      vis[x*p[j]] = true;
      if (x % p[j]==0) break;
    }
  }

  if (s < 2) {
    cout << 1 << endl;
    return 0;
  }

  s = 0;
  FOREACH(x, p) {
    while (s < x) 
      if ((a[2] && s+2<=x) || (s+1==x && !a[1])) {
        --a[2];
        s += 2;
        cout << 2 << ' ';
      } else {
        --a[1];
        s += 1;
        cout << 1 << ' ';
      }
  }

  REP(i, 1, 2)
    while (a[i]--) cout << i << ' ';

  return 0;
}