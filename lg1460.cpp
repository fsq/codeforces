#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int v, n;
vector<int> need;
vector<vector<int>> a;

bool dfs(vector<int>& need, vector<int>& select, int i, int left) {
    if (left==0 || i==a.size()) {
        return all_of(need.begin(), need.end(), [](int x){return x<=0; });
    } else {
        for (int j=0; j<v; ++j) need[j] -= a[i][j];
        select.push_back(i+1);
        if (dfs(need, select, i+1, left-1)) return true;
        select.pop_back();
        for (int j=0; j<v; ++j) need[j] += a[i][j];

        if (dfs(need, select, i+1, left)) return true;
    }
    return false;
}

int main() {
    cin >> v;
    need.resize(v);
    for (int i=0; i<v; ++i) cin >> need[i];

    cin >> n;
    a.resize(n);
    for (int i=0; i<n; ++i) {
        a[i].resize(v);
        for (int j=0; j<v; ++j) cin >> a[i][j];
    }

    int l=1, r=n;
    while (l<r) {
        int mid = (l+r) >> 1;
        vector<int> b = need, select;
        dfs(b, select, 0, mid);
        if (select.empty())
            l = mid + 1;
        else 
            r = mid;
    }

    vector<int> ans, b=need;
    dfs(b, ans, 0, l);
    cout << ans.size() << ' ';
    for (auto x : ans)
        cout << x << ' ';
    cout << endl;

    return 0;
}