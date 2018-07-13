#include <vector>
#include <iostream>
#include <algorithm>

using ll = long long;
using namespace std;

int a[200007];
long long ps[200007];
int n, min_elem;

void init() {
	min_elem = 102;
	for (int i=1; i<=n; ++i) {
		cin >> a[i];
		ps[i] = ps[i-1] + a[i];
		min_elem = min(min_elem, a[i]);
	}
}


// count how many of n^2 <=x and sum of them
pair<ll, ll> count(int x) {
	
}

ll find(ll i) {
	if (i==0) return 0;

	int l = min_elem, r = ps[n];
	pair<ll, ll> res; // rank, prefix
	while (l<r) {
		int m = l + ((r-l)>>1);
		res = count(m);
		if (res.first < i)
			l = m + 1;
		else
			r = m;
	}
	return res.second;
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int q,t=1; t<=T; ++t) {
		cout << "Case #" << t << ": \n";

		cin >> n >> q;
		init();
		
		ll l, r;
		while (q--) {
			cin >> l >> r;
			ll p1 = find(l-1), p2 = find(r);
			cout << p2 - p1<< '\n';
		}
	}
}
