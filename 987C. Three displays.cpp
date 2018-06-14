#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> s(n), c=s;
    vector<vector<int>> f(n, vector<int>(3, INT_MAX));
    for (int i=0; i<n; ++i) cin >> s[i];
    for (int i=0; i<n; ++i) cin >> c[i];

    int ans = INT_MAX;
    for (int i=0; i<n; ++i) {
        f[i][0] = c[i];
        for (int j=0; j<i; ++j)
            if (s[i]>s[j]) {
                f[i][1] = min(f[i][1], f[j][0]+c[i]);
                if (f[j][1]!=INT_MAX)
                    f[i][2] = min(f[i][2], f[j][1]+c[i]);
            }
        ans = min(ans, f[i][2]);
    }

    cout << (ans==INT_MAX ? -1 : ans) << endl;

    return 0;
}