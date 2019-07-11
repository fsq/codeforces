#include "stdc++.h"

string V = "aeiou";

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;

  vector<string> a(n);
  FOR(i, n) cin >> a[i];

  unordered_map<int, unordered_map<char, VI>> s;
  FOR(i, n) {
    const string& x = a[i];
    int len = 0, last = 0;
    FOREACH(c, x) 
      if (auto it=find(ALL(V), c); it != V.end()) {
        ++len;
        last = it - V.begin();
      }
      s[len][last].PB(i);
  }

  unordered_map<int, VI> t;
  VI right;
  FOREACH(&it, s) {
    int len = it.F;
    FOREACH(&v, it.S) {
      auto& arr = v.S;
      if (SZ(arr) & 1) {
        t[len].PB(arr.back());
        arr.pop_back();
      }
      right.insert(right.end(), ALL(arr));
    }
  }

  VI left;
  FOREACH(&it, t) {
    if (SZ(it.S) & 1) {
      it.S.pop_back(); 
    }
    left.insert(left.end(), ALL(it.S));
  }

  while (SZ(left) < SZ(right)) {
    left.insert(left.end(), right.end()-2, right.end());
    right.erase(right.end()-2, right.end());
  }
  cout << (min(SZ(left), SZ(right)))/2 << endl;
  FOR(i, min(SZ(left), SZ(right)))
    cout << a[left[i]] << ' ' << a[right[i]] << '\n';

  return 0;
}