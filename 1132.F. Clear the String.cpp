#include "stdc++.h"

int main() {
  int n;
  string s;
  cin >> n >> s;
  VVI f(n, VI(n));
  FOR(i, n) f[i][i] = 1;
  REP(l, 2, n) 
    REP(i, 0, n-l) {
      int j = i + l - 1;
      f[i][j] = f[i+1][j] + 1;
      REP(k, i+1, j)
        if (s[i] == s[k])
          f[i][j] = min(f[i][j], f[i+1][k-1] + f[k][j]);
    }
  cout << f[0][n-1] << endl;
  return 0;
}