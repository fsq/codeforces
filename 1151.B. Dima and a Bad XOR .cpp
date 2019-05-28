#include "stdc++.h"

int main() {
  int n, m, x;
  cin >> n >> m;
  vector<vector<PII>> f(n, vector<PII>(10, {-1,-1}));
  FOR(i, n) 
    REP(j, 1, m) {
      cin >> x;
      FOR(k, 10)
        if ((x>>k) & 1)
          f[i][k].S = j;
        else 
          f[i][k].F = j;
    }
  
  FOR(k, 10) {
    int one=0, zero=0, both=-1, sum = 0;
    FOR(i, n) 
      if (f[i][k].F != -1 && f[i][k].S != -1) 
        both = i;
      else if (f[i][k].F != -1) {
        ++zero;
      } else if (f[i][k].S != -1) {
        ++one;
        sum ^= 1;
      }
    if (both != -1) {
      cout << "TAK\n";
      FOR(i, n)
        if (i == both)
          cout << (sum ? f[i][k].F : f[i][k].S) << ' ';
        else 
          cout << (f[i][k].F == -1 ? f[i][k].S : f[i][k].F) << ' ';
      return 0;
    } else if (one & 1) {
      cout << "TAK\n";
      FOR(i, n)
        cout << (f[i][k].F == -1 ? f[i][k].S : f[i][k].F) << ' ';
      return 0;
    }
  }
  cout << "NIE\n";

  return 0;
}