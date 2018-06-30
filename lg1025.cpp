#include <iostream>
#include <algorithm>

using namespace std;

// int f[203][9][203];
int f[203][203];

int main() {
    int n, k;
    cin >> n >> k;

    // O(n^3k)
    // for (int i=1; i<=n; ++i) 
    //     f[i][1][i] = 1;
    // for (int i=1; i<=n; ++i)
    //     for (int j=2; j<=k; ++j)
    //         for (int p=1; p<=i; ++p)
    //             for (int pp=1; pp<=p; ++pp)
    //                 f[i][j][p] += f[i-p][j-1][pp];

    // int ans = 0;
    // for (int p=1; p<=n; ++p) ans += f[n][k][p];
    // cout << ans << endl;

    // O(nk)
    for (int i=1; i<=n; ++i) f[i][1] = 1;
    for (int i=2; i<=n; ++i)
        for (int j=2; j<=i; ++j)
            f[i][j] = f[i-j][j] + f[i-1][j-1];
    cout << f[n][k] << endl;

    return 0;
}