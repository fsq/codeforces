#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> a;
    a.resize(n);
    for (int i=0; i<n; ++i)
        cin >> a[i];
    vector<int> p(n);


    vector<int> x = {1};
    while (x.size()<=k) {
        int mn = INT_MAX;
        for (int i=0; i<n; ++i)
            mn = min(mn, x[p[i]]*a[i]);
        x.push_back(mn);
        for (int i=0; i<n; ++i)
            if (x[p[i]]*a[i]==mn)
                ++p[i];
    }
    cout << x.back() << endl;
    return 0;
}