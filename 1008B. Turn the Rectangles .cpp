#include <vector>
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int,int>> a(n);
	for (int i=0; i<n; ++i) cin >> a[i].first >> a[i].second;


	int h = INT_MAX;
    for (auto& p : a) {
    	if (p.first>h) p.first = INT_MIN;
    	if (p.second>h) p.second = INT_MIN;
    	h = max(p.first, p.second);
    	if (h==INT_MIN) {
    		cout << "NO" << endl;
    		return 0;
    	}
    }

    cout << "YES" << endl;

	return 0;
}
