#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n, m;
int v[10007], w[10007], f[10007];

int main() {
    ios::sync_with_stdio(false);
    cin >> m >> n;
    for (int i=0; i<n; ++i)
        cin >> v[i] >> w[i];

    f[0] = 0;
    for (int i=0; i<n; ++i)
        for (int j=w[i]; j<=m; ++j)
            f[j] = max(f[j], f[j-w[i]]+v[i]);

    cout << f[m] << endl;

    return 0;
}