#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];

    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());

    cout << a.size() << '\n';
    for (auto x : a) cout << x << ' ';
    cout << endl;
    return 0;
}