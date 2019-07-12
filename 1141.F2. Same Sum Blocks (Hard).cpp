#include "stdc++.h"

int n;

int main() {
  cin >> n;
  VI a(n+1);
  REP(i, 1, n) cin >> a[i];
  unordered_map<int, vector<PII>> m;
  PER(i, n, 1) {
    int s = 0;
    PER(j, i, 1) {
      s += a[j];
      m[s].PB({j, i});
    }
  }

  int mx = 0;
  vector<PII> ans;
  FOREACH(&pr, m) {
    auto& a = pr.S;
    int r = 0;
    vector<PII> now;
    while (SZ(a)) {
      r = a.back().S;
      now.PB(a.back());
      while (SZ(a) && a.back().F <= r) a.pop_back();
    }
    if (SZ(now) > SZ(ans)) 
      ans = move(now);
  }

  cout << SZ(ans) << endl;
  FOREACH(&seg, ans)
    cout << seg.F << ' ' << seg.S << endl;
  return 0;
}