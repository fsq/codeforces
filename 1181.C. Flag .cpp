#include "stdc++.h"

int n, m;
vector<string> a;

int encode(char a, char b, char c, int h) {
  return ((a-'a')*10000+(b-'a')*100+(c-'a'))*1000 + h;
}

int main() {
  cin >> n >> m;
  a.resize(n+1);
  a[0] = string(m+1, ' ');
  REP(i, 1, n) {
    cin >> a[i];
    a[i].insert(a[i].begin(), ' ');
  }

  VVI up(n+1, VI(m+1)), s = up, lf = up;
  LL ans = 0;
  REP(i, 1, n) 
    REP(j, 1, m) {
      up[i][j] = (a[i][j]==a[i-1][j] ? up[i-1][j] : 0) + 1;
      int h = up[i][j];
      if (i-h > 0 && up[i-h][j]==h && i-2*h>0 && up[i-2*h][j]>=h) 
        s[i][j] = encode(a[i][j], a[i-h][j], a[i-2*h][j], h);
      if (s[i][j]) {
        lf[i][j] = (s[i][j-1]==s[i][j] ? lf[i][j-1] : 0) + 1;
        ans += lf[i][j];
      }
    }
  cout << ans << endl;
  return 0;
}