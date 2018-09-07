#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, l;
    cin >> l >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];

    int mn=0, mx=0;
    for (auto x : a) {
        mn = max(mn, min(l+1-x, x));
        mx = max(mx, max(l+1-x, x));
    }
    cout << mn << ' ' << mx << endl;
    return 0;
}