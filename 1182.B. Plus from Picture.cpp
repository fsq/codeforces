#include "stdc++.h"

VI dx = {-1, 0, 1, 0};
VI dy = {0, 1, 0, -1};

bool cross(const vector<string>& a, int x, int y) {
  FOR(dir, 4)
    if (a[x+dx[dir]][y+dy[dir]] != '*')
      return false;
   return a[x-1][y-1]=='.' || a[x-1][y+1]=='.' || a[x+1][y-1]=='.' || a[x+1][y+1]=='.';
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  FOR(i, n) cin >> a[i];

  bool found = false;
  REP(i, 1, n-2) REP(j, 1, m-2) 
    if (a[i][j]=='*' && cross(a, i, j)){
      a[i][j] = '.';
      found = true;
      FOR(dir, 4) {
        int x=i+dx[dir], y=j+dy[dir];
        while (x>=0 && x<n && y>=0 && y<m && a[x][y]=='*') {
          a[x][y] = '.';
          x += dx[dir];
          y += dy[dir];
        }
      }
      goto out;
    }

  out:
  if (!found) {
    cout << "NO\n";
    return 0;
  }
  FOR(i, n) FOR(j, m)
    if (a[i][j] == '*') {
      cout << "NO\n";
      return 0;
    }
  cout << "YES\n";
  return 0;
}