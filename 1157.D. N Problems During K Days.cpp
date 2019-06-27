#include "stdc++.h"

int n, k, s=0;

bool ok(CVI& a, int x) {
  LL t = s, p = a[x];
  REP(i, x+1, k) {
    t += (p*=2) - a[i];
    if (t > n) return false;
  }
  return true;
}

int main() {
  cin >> n >> k;
  VI a(1+k);

  REP(i, 1, k) {
    s += a[i] = i;
    if (s > n) {
      cout << "NO\n";
      return 0;
    }
  }
  REP(i, 1, k) a[i] += (n-s) / k;
  s += (n-s) / k * k;
  if (s != n) {
    int l=1, r=k;
    while (l < r) {
      int mid = (l+r) >> 1;
      if (!ok(a, mid))
        l = mid + 1;
      else 
        r = mid;
    }
    REP(i, l+1, k) {
      s += a[i-1]*2 - a[i];
      a[i] = a[i-1] << 1;
    }
    a[l] += n - s;
    if ((l<k && a[l] >= a[l+1]) || (l>1 && a[l] > a[l-1]*2)) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  REP(i, 1, k)
    cout << a[i] << ' ';
  cout << endl;
  return 0;
}