#include "stdc++.h"

int main() {
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int n = SZ(s);
  LL ans = (LL)(n+1)*n/2;
  FOR(i, n) {
    REP(j, i, n-1) {
      bool find = false;
      PER(k, j-1, i+1)
        if (s[k]==s[j] && 2*k-j>=i && s[2*k-j]==s[j]) {
          find = true;
          break;
        }
      if (find) break;
      --ans;
    }
  }
  
  cout << ans << endl;
  return 0;
}