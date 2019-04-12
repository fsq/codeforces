#include "stdc++.h"

int n, m;
unordered_set<int> e[200003];

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i=0, x, y; i<m; ++i) {
    cin >> x >> y;
    e[x].insert(y);
    e[y].insert(x);
  }

  VI ans, left(n);
  iota(ALL(left), 1);
  
  while (left.size()) {
    VI cc = {left.front()};
    swap(left.front(),left.back());
    left.pop_back();

    for (int i=0; i<cc.size(); ++i)
      for (int j=0; j<left.size(); )
        if (!e[cc[i]].count(left[j])) {
          cc.push_back(left[j]);
          swap(left[j], left.back());
          left.pop_back();
        } else 
          ++j;
    ans.PB(cc.size());
  }
  cout << ans.size() << endl;
  sort(ALL(ans));
  FOREACH(x, ans) cout << x << ' '; cout << endl;
  return 0;
}