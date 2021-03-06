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


int ask(int x, CVI& a) {
  cout << 1 << ' ' << SZ(a) << ' ';
  cout << x << ' ';
  FOREACH(x, a) cout << x << ' ';
  cout.flush();
  int d;
  cin >> d;
  return d;
}

VI build(int l, int r) {
  VI a(r-l+1);
  iota(ALL(a), l);
  return a;
}

int main() {
  int t, n, l, r;
  cin >> t;
  while (t--) {
    cin >> n;
    VI a = build(2, n);
    int md = ask(1, a);
    l = 2, r = n;
    while (l < r) {
      int mid = (l+r) >> 1;
      VI a = build(l, mid);
      int d = ask(1, a);
      if (d != md)
        l = mid + 1;
      else 
        r = mid;
    }
    a.clear();
    REP_IF(i, 1, n, i!=l) a.PB(i);
    md = ask(l, a);
    cout << -1 << ' ' << md << endl;
  }
  return 0;
}