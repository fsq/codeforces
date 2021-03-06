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
#define MEMSET(container, value)  memset(container, value, sizeof(container))
#define FILL(container, value)    fill(container.begin(), container.end(), value)
#define FILL0(container)          fill(container.begin(), container.end(), 0)
#define ALL(container)            (container).begin(), (container).end()
#define SZ(container)             (int)((container).size())

#define BACK(set_map)       *prev((set_map).end(), 1)
#define FRONT(set_map)      *(set_map).begin()

using PII = std::pair<int,int>;
using LL  = long long;
using VI  = std::vector<int>;
using VLL = std::vector<LL>;
using VVI = std::vector<VI>;
using VVLL = std::vector<VLL>;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t, mx=0, my=0;
    scanf("%d\n", &t);
    int x, y;
    char c;
    while (t--) {
        scanf("%c %d %d\n", &c, &x, &y);
        if (x < y) swap(x, y);
        if (c == '+') {
            mx = max(mx, x);
            my = max(my, y);
        } else 
            cout << ((x >= mx && y >= my) ? "YES\n" : "NO\n");
    }
    return 0;
}