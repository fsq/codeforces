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
    int t, n, r;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> a;
        vector<int> g(n);

        for (int l,r,i=0; i<n; ++i) {
            cin >> l >> r;
            a.push_back({l, r, i});
        }

        sort(ALL(a), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        r = a[0][1];
        bool found = false;
        for (int i=0; i<n; ++i) 
            if (a[i][0]>r) {
                for (int j=i; j<n; ++j) g[a[j][2]] = 2;
                found = true;
                break;
            } else {
                r = max(r, a[i][1]);
                g[a[i][2]] = 1;
            }
        if (!found)
            cout << -1;
        else 
            for (int i=0; i<n; ++i)
                cout << g[i] << ' ';
        cout << endl;
        
    }
    return 0;
}