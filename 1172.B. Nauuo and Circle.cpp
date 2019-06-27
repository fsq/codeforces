#include "stdc++.h"

const int M = 998244353;
int n;
VVI e;
VI A, tot;

int MUL(int a, int b) {
  return (LL)a*b % M;
}

// int dp(int x, int pre) {
//   int f = 1;
//   tot[x] = 1;
//   FOREACH_IF(y, e[x], y!=pre) {
//     f = MUL(f, dp(y, x));
//     f = MUL(f, SZ(e[y]));
//     tot[x] += tot[y];
//   }
//   f = MUL(f, A[SZ(e[x])-(pre!=0)]);
//   return f;
// }

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  A.resize(n+1);
  tot.resize(n+1);
  A[0] = 1;
  REP(i, 1, n)
    A[i] = MUL(A[i-1], i);
  e.resize(n+1);
  for (int u,v,i=0; i<n-1; ++i) {
    cin >> u >> v;
    e[u].PB(v);
    e[v].PB(u);
  }

  // cout << MUL(dp(1, 0), n) << endl;
  int f = 1;
  REP(i, 1, n)
    f = MUL(f, A[SZ(e[i])]);
  cout << MUL(f, n) << endl;

  return 0;
}

