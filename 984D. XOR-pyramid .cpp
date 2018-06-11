#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int f[5003][5003], g[5003][5003];
bool vis[5003][5003];
vector<int> a;

int dp(int l, int r) {
    if (l==r) return a[l];
    if (vis[l][r]) return g[l][r];
    vis[l][r] = true;
    g[l][r] = max(f[r-l+1][l], max(dp(l, r-1), dp(l+1, r)));
    return g[l][r];
}


int main() {
    int n;
    cin >> n;
    a.resize(n+1);
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        f[1][i] = a[i];
    }

    for (int i=2; i<=n; ++i) 
        for (int j=1; j+i-1<=n; ++j) 
            f[i][j] = f[i-1][j] ^ f[i-1][j+1];

    int m;
    cin >> m;
    for (int l,r; m; m--) {
        cin >> l >> r;
        cout << dp(l, r) << '\n';

    }

    return 0;
}