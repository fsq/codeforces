#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];

    while (m--) 
        next_permutation(a.begin(), a.end());

    for (auto x : a) cout << x << ' '; 
    cout << endl;

    return 0;
}