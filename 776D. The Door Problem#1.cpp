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

const int N = 1e5 + 7;
int r[N];
VI m[N];
int fa[N], g[N];

int find(int x) {
  if (fa[x] == x) return x;
  int f = find(fa[x]);
  g[x] ^= g[fa[x]];
  fa[x] = f;
  return f;
}

int main() {
  ios::sync_with_stdio(false);
	int n, e;

  cin >> n >> e;
  REP(i, 1, n) 
    cin >> r[i];
  

  for (int x,i=1; i<=e; ++i) {
    fa[i] = i;
    cin >> x;
    for (int b,j=0; j<x; ++j) {
      cin >> b;
      m[b].PB(i);
    }
  }

  REP(i, 1, n) {
    int x = m[i][0], y = m[i][1];
    int fx=find(x), fy=find(y);
    if (fx != fy) {
      fa[fx] = fy;
      g[fx] = (!r[i]) ^ g[y] ^ g[x];
    } else if (g[x] ^ g[y] ^ (!r[i])) {
      cout << "NO\n";
      return 0;
    }
  }

  cout << "YES\n";

	return 0;
}