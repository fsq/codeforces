#include "stdc++.h"

bool vis[2750135];
const LL MAXP = 2750131;
VI p = {MAXP};

int divisor(int x) {
  FOREACH(i, p)
    if (x % i == 0)
      return x / i;
}

int main() {
  int n, mx = 0, x;
  cin >> n;
  unordered_map<int,int> b;
  FOR(i, n<<1) {
    cin >> x;
    ++b[x];
    mx = max(mx, x);
  }

  MEMSET0(vis);
  unordered_map<int, int> ind;
  for (int x=2; SZ(p)<=min(mx, 200000); ++x) {
    if (!vis[x]) {
      p.PB(x);
      ind[x] = SZ(p) - 1;
    }
    for (int j=1; j<SZ(p) && (LL)p[j]*x<=mx; ++j) {
      vis[p[j]*x] = true;
      if (x % p[j]==0) break;
    }
  }

  VI ans;
  PER(i, mx, 1)
    if (b[i])
      if (ind.count(i)) {
        ans.insert(ans.end(), b[i], ind[i]);
        b[ind[i]] -= b[i];
      } else {
        ans.insert(ans.end(), b[i], i);
        b[divisor(i)] -= b[i];
      }

  FOREACH(x, ans) cout << x << ' '; cout << endl;
  return 0;
}