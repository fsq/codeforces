#include <iostream>
#include <vector>

using namespace std;

// DP
// preprocess the inc/dec seq for each index

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a = {0};
    for (int j,i=0; i<n; ++i) {
        cin >> j;
        a.push_back(j);
    }

    vector<int> l(n+1, 0), r = l;

    r[n] = n;
    for (int i=n-1; i>=1; --i) 
        if (a[i]<=a[i+1])
            r[i] = r[i+1];
        else 
            r[i] = i;
    l[1] = 1;
    for (int i=2; i<=n; ++i)
        if (a[i-1]>=a[i])
            l[i] = l[i-1];
        else
            l[i] = i;

    for (int x,y,i=0; i<m; ++i) {
        cin >> x >> y;
        cout << (l[y]<=r[x] ? "Yes" : "No") << '\n';
    }

    return 0;
}