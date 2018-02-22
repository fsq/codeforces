#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<bool> a(n+1, false);
        for (int j,i=0; i<k; ++i) {
            cin >> j;
            a[j] = true;
        }
        int maxgap = -1;
        for (int i=1; i<=n; ++i) {
            int mindis = INT_MAX;
            for (int j=i; j>=1; --j)
                if (a[j]) {
                    mindis = i - j + 1;
                    break;
                }
            for (int j=i+1; j<=n; ++j)
                if (a[j]) {
                    mindis = min(mindis, j-i+1);
                    break;
                }
            maxgap = max(maxgap, mindis);
        }

        cout << maxgap << '\n';
    }
    return 0;
}