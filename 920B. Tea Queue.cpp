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
        int n;
        cin >> n;
        vector<int> l(n+1, 0), r = l;
        vector<pair<int,int>> q;
        for (int a,b,i=1; i<=n; ++i) {
            cin >> a >> b;
            l[i] = a;
            r[i] = b;
            q.push_back({a, i});
        }
        sort(q.begin(), q.end());
        int now = 0;
        vector<int> ans(n+1, 0);
        for (int i=0; i<q.size(); ++i) {
            int li = q[i].first;
            int ind = q[i].second;
            // time for tea
            now = max(now, li);
            // get tea 
            if (r[ind]>=now) {
                ans[ind] = now;
                ++now;
            }
        }
        for (int i=1; i<n; ++i)
            cout << ans[i] << ' ';
        cout << ans[n] << '\n';
    }
    return 0;
}