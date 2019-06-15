#include "stdc++.h"

int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<PII> a(m);
  FOR(i, m) {
    cin >> a[i].F >> a[i].S;
    a.PB({a[i].S, a[i].F});
  }
  m <<= 1;
  
  sort(ALL(a), [=](PII& a, PII& b) {
    if (a.F != b.F)
      return a.F < b.F;
    return (a.S+n-a.F) % n < (b.S+n-b.F) % n;
  });
  VI s;
  for (int j,i=0; i<m; i=j) {
    for (j=i; j<m && a[j].F==a[i].F; ++j) 
      s.PB((a[j].S+n-a[i].F) % n);
    s.PB(- (j==m ? a[0].F+n-a[i].F : a[j].F-a[i].F));
  }

  m = SZ(s);
  VI next(m);
  for (int j,i=1; i<m; ++i) {
    for (j=next[i-1]; j>0 && s[j]!=s[i]; j=next[j-1]);
    next[i] = j + (s[i]==s[j]);
  }

  auto t = s;
  FOR(i, m) t.PB(t[i]);
  int i, j;
  for (j=0, i=1; i<m*2-1 && j<m; )
    if (t[i] == s[j])
      ++i, ++j;
    else if (j==0)
      ++i;
    else
      j = next[j-1];
  cout << (j==m ? "YES" : "NO") << endl;
  return 0;
}