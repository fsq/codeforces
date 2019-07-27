#include "stdc++.h"


const int N = 2003;
VI e[N], ind, f;
int fa[N], n, m;

int find(int x) {
  return fa[x]==x ? x : fa[x]=find(fa[x]);
}

int main() {
  ios::sync_with_stdio(false);

  cin >> n >> m;
  ind.resize(n+m+1);
  f = VI(n+m+1, 1);
  iota(fa+1, fa+n+m+1, 1);

  vector<string> rel(n+1);
  REP(i, 1, n) {
    cin >> rel[i];
    FOR(j, m) 
      if (rel[i][j] == '=') {
        fa[find(i)] = find(j+1+n);
      }
  }

  REP(i, 1, n) 
    FOR(j, m) {
      int fi = find(i), fj = find(j+1+n);
      if (rel[i][j] != '=') {
        if (fi == fj) {
          cout << "NO\n";
          return 0;
        }
        if (rel[i][j] == '>') swap(fi, fj);
        e[fi].PB(fj);
        ++ind[fj];
      } 
    }
  

  queue<int> q;
  REP(i, 1, n+m)
    if (fa[i]==i && !ind[i]) 
      q.push(i);
  while (!q.empty()) {
    POP(x, q);
    for (auto y : e[x]) {
      f[y] = max(f[y], f[x]+1);
      if (--ind[y] == 0)
        q.push(y);
    }
  }

  REP(i, 1, n+m) {
    f[i] = f[find(i)];
    if (ind[i]) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  REP(i, 1, n) cout << f[i] << ' '; cout << endl;
  REP(i, n+1, n+m) cout << f[i] << ' '; cout << endl;

  return 0;
}