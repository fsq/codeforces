#include "stdc++.h"

LL n, m, r, k;

LL f(int x, int y) {
  LL lx=max(1ll, x-r+1), rx=min<LL>(n-r+1, x);
  LL ly=max(1ll, y-r+1), ry=min<LL>(m-r+1, y);
  return (rx-lx+1) * (ry-ly+1);
}

LL encode(int x, int y) {
  return LL(x) * 1000000ll + y;
}

int main() {
  cin >> n >> m >> r >> k;
  set<VLL, std::greater<VLL>> st;
  st.insert({f(n/2+1, m/2+1), n/2+1, m/2+1});
  double tot = 0;
  VI dx = {-1, 0, 1, 0};
  VI dy = {0, 1, 0, -1};
  unordered_set<LL> vis;
  vis.insert(encode(n/2+1, m/2+1));

  for (int put=0; put<k; ++put) {
    VLL now = FRONT(st);
    st.erase(st.begin());
    int x = now[1], y = now[2];
    tot += now[0];
    for (int dir=0; dir<4; ++dir) {
      int tx=x+dx[dir], ty=y+dy[dir];
      if (tx>0 && tx<=n && ty>0 && ty<=m && !vis.count(encode(tx, ty))) {
        st.insert({f(tx, ty), tx, ty});
        vis.insert(encode(tx, ty));
      }
    }
  }
  cout.precision(9);
  cout << std::fixed << tot/((n-r+1)*(m-r+1)) << endl;
  return 0;
}