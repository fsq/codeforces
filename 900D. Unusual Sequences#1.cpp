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


const int M = 1e9 + 7;

void add(LL& x, LL y) {
  x = (x + y + M) % M;
}

LL p2(int x) {
  LL ans = 1, p = 2;
  while (x) {
    if (x & 1)
      ans = ans * p % M;
    x >>= 1;
    p = p * p % M;
  }
  return ans;
}

int main() {
  int x, y;
  cin >> x >> y;
  if (y % x) 
    cout << 0 << endl;
  else {
    y /= x;
    VI d;
    for (int i=1; i*i<y; ++i) 
      if (y % i == 0) 
        d.PB(i), d.PB(y / i);
    if ((int)sqrt(y)*(int)sqrt(y) == y)
      d.PB(sqrt(y));

    sort(ALL(d));
    VLL f(SZ(d));
    f[0] = 1;
    FORI(i, d) {
      f[i] = p2(d[i] - 1);
      FOR(j, i) 
        if (d[i] % d[j] == 0) 
          add(f[i], -f[j]);
    }
    cout << f.back() << endl;
  }
  return 0;
}