#include "stdc++.h"

using PSS = pair<string, string>;

string build(LL b, LL a) {
  LL g = gcd(a, b);
  b /= g, a /= g;
  return to_string(a) + ":" + to_string(b);
}

PSS getline(PII a, PII b) {
  if (a.F > b.F) swap(a, b);
  if (a.F == b.F) return {"0", to_string(a.F)};
  return { build(b.S-a.S, b.F-a.F),
            build((LL)a.S*(b.F-a.F) - (b.S-a.S)*(LL)a.F, b.F-a.F)};
}

int main() {
  int n;
  string k, b;
  cin >> n;
  vector<PII> a(n);
  FOR(i, n) cin >> a[i].F >> a[i].S;

  unordered_map<string, unordered_set<string>> m;
  FOR(i, n) 
    REP(j, i+1, n-1) {
      tie(k, b) = getline(a[i], a[j]);
      m[k].insert(b);
    }

  int nl = accumulate(m.begin(), m.end(), 0, [](int x, auto& it){
    return x + it.S.size();
  });

  LL ans = 0;
  for (auto it=m.begin(); it!=m.end(); ++it) 
    ans += it->second.size() * (nl - it->second.size());
  
  cout << ans/2 << endl;
  
  return 0;
}