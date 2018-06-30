#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, s, a, b;
	cin >> n >> s >> a >> b;

	vector<int> v;
	for (int x,y,i=0; i<n; ++i) {
		cin >> x >> y;
		if (a+b>=x) v.push_back(y);
	}

	sort(v.begin(), v.end(), std::greater<int>());
	int ans = 0;
	while (!v.empty() && s>=v.back()) {
		++ans;
		s -= v.back();
		v.pop_back();
	}

	cout << ans << endl;
	return 0;
}