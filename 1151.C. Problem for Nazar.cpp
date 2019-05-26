#include "stdc++.h"

const int M = 1e9 + 7;

LL pow2(int p) {
  if (p==0) return 1;
  if (p==1) return 2;
  LL x = pow2(p/2);
  if (p&1)
    return x*x %M *2 %M;
  else
    return x*x %M;
}

int main() {
  LL l, r;
  cin >> l >> r;
  VLL a{-1, 0};
  LL len = 1, p = 0, i = 0, ans = 0;
  LL div2 = pow2(M-2);
  while (p <= r) {
    LL pl = p + 1, pr = p + len;

    LL x = max(pl, l), y = min(pr, r);
    if (x <= y) {
      LL ax = a[i] + (x-p) * 2;
      LL ay = a[i] + (y-p) * 2;
      LL add = ((ax+ay)%M) * ((y-x+1)%M) %M * div2%M;
      ans = (ans + add) % M;
    }
    len <<= 1;
    a[i] += len;
    i ^= 1;
    p = pr;
  }
  cout << ans << endl;
  return 0;
}