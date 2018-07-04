#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

int split(const vector<int>& a, int m) {
    int ret = 1;
    for (int s=0, i=0; i<a.size(); ++i)
        if (s+a[i] > m) {
            ++ret;
            s = a[i];
        } else 
            s += a[i];
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];

    int l = *max_element(a.begin(), a.end()), r = 1e9;
    while (l<r) {
        int mid = l + ((r-l) >> 1);
        if (split(a, mid) > m)
            l = mid + 1;
        else 
            r = mid;
    }
    cout << l << endl;

    return 0;
}