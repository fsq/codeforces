#include "stdc++.h"

int n;
const int M = 1e9 + 7;
int f[2][2003][2003];
int v[2][2003][2003];

int dp(int vis, int i, int s) {
  if (s < 0 || s > n-i) return -1;
  
  if (v[vis][i][s]) return f[vis][i][s];  
  v[vis][i][s] = true;
  int& ans = f[vis][i][s];
  if (i == n) {
    ans = 0;
  } else {
    if (vis) {
      int fl = dp(0, i+1, s+1), fr = dp(0, i+1, s-1);
      if (fl==-1 && fr==-1)
        ans = -1;
      else if (fl==-1 || fr==-1)
        ans = max(fl, fr);
      else
        ans = (fl + fr) % M;
    } else {
      FOR(x, 2) FOR(y, 2)
        if (!(x && y)) {
        int fl = dp(x, i+1, s+1), fr = dp(y, i+1, s-1), now = 0;
        if (fl==-1 && fr==-1)
          now = -1;
        else if (fl==-1 || fr==-1)
          now = max(fl, fr);
        else 
          now = (fl + fr) % M;
        ans = max(ans, now);
      }
    }
  }
  if (ans != -1) ans += vis;
  return ans;
}

int main() {
  cin >> n;
  n <<= 1;
  
  MEMSET0(v);
  auto ans = dp(0, 0, 0);
  cout << ans << endl;
  return 0;
}