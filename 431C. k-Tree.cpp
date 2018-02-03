#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, d;
    cin >> n >> k >> d;

    const long long M = 1e9 + 7;

    vector<long long> f(n+1, 0), g = f;
    f[0] = 1;

    for (int i=1; i<=n; ++i) {
        for (int t=1; t<=d-1 && i-t>=0; ++t) {
            f[i] += f[i-t];
            g[i] += g[i-t];
            if (f[i]>=M) f[i] %= M;
            if (g[i]>=M) g[i] %= M;
        }
           // printf("%d %d %d\n", i, f[i], g[i]);
        for (int t=d; t<=k && i-t>=0; ++t) {
            g[i] += f[i-t] + g[i-t];
            if (g[i]>=M) g[i] %= M;
        }
        // printf("%d %d %d\n", i, f[i], g[i]);
    }
    cout << g[n] << endl;
    return 0;
}