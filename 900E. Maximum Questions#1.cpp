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


int main() {
  int n, m;
  string s;
  cin >> n >> s;
  cin >> m;
  s = " " + s;

  VI cq(n + 1);
  VVI ca(n+1, VI(2)), cb = ca;
  REP(i, 1, n) {
    cq[i] = cq[i-1] + (s[i]=='?');
    ca[i][i & 1] = ca[i-1][i & 1] + (s[i]=='a');
    ca[i][!(i & 1)] = ca[i-1][!(i & 1)];
    cb[i][i & 1] = cb[i-1][i & 1] + (s[i]=='b');
    cb[i][!(i & 1)] = cb[i-1][!(i & 1)];
  }

  vector<PII> f(n+1);
  REP(i, 1, n) {
    f[i] = f[i-1];
    if (i >= m) {
      PII r = f[i-m];
      int aodd = ca[i][!((i^m) & 1)] - ca[i-m][!((i^m) & 1)];
      int aevn = ca[i][(i^m) & 1] - ca[i-m][(i^m) & 1];
      int bodd = cb[i][!((i^m) & 1)] - cb[i-m][!((i^m) & 1)];
      int bevn = cb[i][(i^m) & 1] - cb[i-m][(i^m) & 1];
      if (!aevn && !bodd) {
        ++r.first;
        r.second += m - (aodd+bevn);
        if (r.first>f[i].first || r.first==f[i].first && r.second<f[i].second)
          f[i] = r;
      }
    }
  }
  cout << f.back().second << endl;

  return 0;
}