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


const int N = 100007;
int n, m, q;
VI e[N];
VI f[N][20];
int lca[N][20];
int h[N], l, c=10;

VI combine(CVI& a, CVI& b) {
	VI ans;
	for (int i=0, j=0; SZ(ans)<c && (i<SZ(a) || j<SZ(b)); ) 
		if (i<SZ(a) && (j==SZ(b) || a[i]<b[j]))
			ans.PB(a[i++]);
		else
			ans.PB(b[j++]);
	return ans;
}

void dfs(int x, int fa) {
	h[x] = h[fa] + 1;
	lca[x][0] = fa;
	for (int k=1; k<=l; ++k) 
		if (int mid=lca[x][k-1]; mid && lca[mid][k-1]) {
			lca[x][k] = lca[mid][k-1];
			f[x][k] = combine(f[x][k-1], f[mid][k-1]);
		} else	
			break;

	FOREACH_IF(y, e[x], y!=fa) 
		dfs(y, x);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	l = (int) ceil(log(n) / log(2));
	for (int x,y,i=0; i+1<n; ++i) {
		cin >> x >> y;
		e[x].PB(y), e[y].PB(x);
	}

	for (int x,i=1; i<=m; ++i) {
		cin >> x;
		f[x][0].PB(i);
	}

	REP(i, 1, n) {
		sort(ALL(f[i][0]));
		f[i][0].resize(min(10, SZ(f[i][0])));
	}

	MEMSET0(h);
	MEMSET0(lca);
	dfs(rand()%n + 1, 0);

	for (int x,y; q; q--) {
		cin >> x >> y >> c;
		if (h[x] < h[y]) swap(x, y);

		VI ans;
		for (int k=l; h[x]>h[y] && k>=0; --k)
			if (h[x]-(1<<k) >= h[y]) {
				ans = combine(ans, f[x][k]);
				x = lca[x][k];
			}

		for (int k=l; k>=0; --k) 
			if (lca[x][k] != lca[y][k]) {
				ans = combine(ans, f[x][k]);
				ans = combine(ans, f[y][k]);
				x = lca[x][k];
				y = lca[y][k];
			}
		ans = combine(ans, f[x][0]);
		if (x != y) {
			ans = combine(ans, f[y][0]);
			ans = combine(ans, f[lca[y][0]][0]);
		}

		cout << SZ(ans) << ' ';
		FOREACH(x, ans) cout << x << ' ';
		cout << '\n';
	}

	return 0;
}
