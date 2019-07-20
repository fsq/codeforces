#include "stdc++.h"

int main() {
  int n, k;
  cin >> n >> k;

  unordered_map<int, int> p;
  
  VI a(n+1);
  REP(i, 1, n) 
    cin >> a[i];
  sort(ALL(a));
  REP(i, 1, n) 
    if (!p.count(a[i]))
      p[a[i]] = i;
  

  VVI f(n+1, VI(k+1));
  f[1][1] = 1;
  REP(i, 2, n) 
    REP(j, 1, k) {
      f[i][j] = max(f[i][j-1], max(f[i-1][j-1]+1, f[i-1][j]));
      REP(t, a[i]-5, a[i])
        if (p.count(t)) {
          f[i][j] = max(f[i][j], f[p[t]-1][j-1] + (i-p[t]+1));
          break;
        }
    }
  cout << f[n][k] << endl;
  return 0;
}