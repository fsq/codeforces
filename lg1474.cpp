#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int v, n;
    cin >> n >> v;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];

    vector<long long> pre(v+1), f(v+1);
    pre[0] = 1;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<=v; ++j)
            f[j] = pre[j] + (j>=a[i] ? f[j-a[i]] : 0);
        f.swap(pre);
    }

    cout << pre.back() << endl;
    return 0;
}