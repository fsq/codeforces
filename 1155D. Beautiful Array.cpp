#include "stdc++.h"

int main() {
  int n, x;
  cin >> n >> x;

  VLL a(n+1);
  REP(i, 1, n) cin >> a[i];
  
  VLL f(n+1), g(n+1);
  LL mg = 0;

  REP(i, 1, n) {
    g[i] = max(0ll, max(g[i-1]+a[i], a[i]));
    mg = max(mg, g[i]);
  }
    if (x > 0) {
    cout << mg * x << endl;
  } else {
    VLL s(n+2);
    PER(i, n, 1) 
      s[i] = max(0ll, max(s[i+1]+a[i], a[i]));

    f[1] = x * a[1];
    LL ans = f[1] + s[2];

    REP(i, 2, n) {
      f[i] = max(f[i-1], g[i-1]) + a[i] * x;
      ans = max(ans, f[i] + s[i+1]);
    }
    cout << max(ans, mg) << endl;
  }

  return 0;
}