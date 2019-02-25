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

const int MAXN = 200007;
VI primes;
int n, ans = 0;
vector<PII> f[MAXN];
VI e[MAXN];
VI a;

void init() {
	VI vis(MAXN+1);
	REP(i, 2, MAXN) {
		if (!vis[i]) primes.PB(i);
		for (int j=0; j<primes.size() && primes[j]*i<=MAXN; ++j) {
			vis[primes[j]*i] = true;
			if (i%primes[j] == 0) break;
		}
	}

	cin >> n;
	a.resize(n + 1);
	REP(i, 1, n) cin >> a[i];
	for (int u,v,i=0; i+1<n; ++i) {
		cin >> u >> v;
		e[u].PB(v), e[v].PB(u);
	}
}

VI factorization(int x) {
	VI ans;
	for (int i=0; x>1 && x>=primes[i]*primes[i]; ++i)
		if (x % primes[i] == 0) {
			ans.PB(primes[i]);
			while (x%primes[i] == 0) 
				x /= primes[i];
		}
	if (x > 1) ans.PB(x);
	return ans;
}

void dfs(int x, int pre) {
	vector<PII> sons;
	FOREACH(y, e[x])
		if (y != pre) {
			dfs(y, x);
			FOREACH(pr, f[y]) sons.PB(move(pr));
		}
		
	sort(ALL(sons));
	for (int j,i=0; i<SZ(sons); i=j) {
		int mx1=0, mx2=0;
		for  (j=i; j < SZ(sons) && sons[j].F==sons[i].F; ++j) 
			if (sons[j].S > mx1) 
				mx2 = mx1, mx1 = sons[j].S;
			else if (sons[j].S > mx2)
				mx2 = sons[j].S;
	
		if (a[x]%sons[i].F == 0) {
			ans = max(ans, mx1+mx2+1);
			f[x].PB({sons[i].F, max(mx1, mx2)+1});
			while (a[x]%sons[i].F == 0) a[x] /= sons[i].F;
		}
	}

	auto factors = factorization(a[x]);
	FOREACH(factor, factors) {
		f[x].emplace_back(factor, 1);
		ans = max(ans, 1);
	}
}

int main(int argc, char const *argv[]) {	
	ios::sync_with_stdio(false);

	init();

	dfs(1, -1);

	cout << ans << endl;

	return 0;
}

	