#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#include <memory>
#include <list>
#include <climits>
#include <fstream>
#include <sstream>
#include <random>
#include <functional>

#define PB                  push_back
#define F                   first
#define S                   second

#define REP(i,from,to)      for(auto i=(from); i<=(to); ++i)
#define PER(i,from,to)      for(auto i=(from); i>=(to); --i)
#define REP_IF(i,from,to,assert)   for(auto i=(from); i<=(to); ++i) if (assert)

#define FOR(i,less_than)    for (auto i=0; i<(less_than); ++i)
#define FORI(i, container)  for (auto i=0; i<(container).size(); ++i)
#define FORI_IF(i, container, assert) for (auto i=0; i<(container).size(); ++i) if (assert)
#define ROFI(i, container)  for (auto i=SZ(container)-1; i>=0; --i)
#define FOREACH(elem, container)  for (auto elem : (container))
#define FOREACH_IF(elem, container, assert) for (auto elem : (container)) if (assert)

#define MEMSET(container, value)  memset(container, value, sizeof(container))
#define MEMSET0(container)        memset(container, 0, sizeof(container))
#define FILL(container, value)    fill(container.begin(), container.end(), value)
#define FILL0(container)    fill(container.begin(), container.end(), 0)
#define ALL(container)            (container).begin(), (container).end()
#define SZ(container)             (int)((container).size())

#define BACK(set_map)       *prev((set_map).end(), 1)
#define FRONT(set_map)      *(set_map).begin()

#define POP(var, container) auto var=(container.front()); container.pop();

using PII = std::pair<int,int>;
using LL  = long long;
using VI  = std::vector<int>;
using CVI = const VI;
using VLL = std::vector<LL>;
using VVI = std::vector<VI>;
using VVLL = std::vector<VLL>;

using namespace std;

const int N = 1007;
int f[N][N];
vector<string> a;

int main() {
  int n, m, k, sx, sy, tx, ty;
  cin >> n >> m >> k;

  MEMSET0(f);
  a.resize(n);
  FOR(i, n) cin >> a[i];

  cin >> sx >> sy >> tx >> ty;
  --sx, --sy, --tx, --ty;
  if (sx==tx && sy==ty) {
    cout << 0 << endl;
    return 0;
  }

  queue<PII> q;
  q.push({sx, sy});
  VI dx = {-1, 0, 1, 0};
  VI dy = {0, 1, 0, -1};
  for (int x,y; !q.empty(); ) {
    tie(x, y) = q.front(); q.pop();
    for (int dir=0; dir<4; ++dir) {
      for (int nx,ny,l=1; l<=k; ++l) {
        nx = x + l*dx[dir];
        ny = y + l*dy[dir];
        if (!(nx>=0 && nx<n && ny>=0 && ny<m && a[nx][ny] && 
             (a[nx][ny]=='.' || a[nx][ny]=='x')))
          break;
        if (a[nx][ny]=='.') {
          a[nx][ny] = 'x';
          f[nx][ny] = f[x][y] + 1;
          if (nx==tx && ny==ty) goto last;
          q.push({nx, ny});
        }
      }
    }
  }
  last:
  cout << (f[tx][ty]==0 ? -1 : f[tx][ty]) << endl;

  return 0;
}