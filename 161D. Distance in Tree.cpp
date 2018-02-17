#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// tree DP
// O(nk) time

int n, k;
vector<vector<int>> edges;
vector<bool> vis;

long long ans;

vector<int> dp(int node) {
    vis[node] = true;

    vector<int> cnt(k+1, 0);

    for (auto nxt : edges[node])
        if (!vis[nxt]) {
            auto info = dp(nxt);
            for (int i=0; i+1<k; ++i) 
                ans += cnt[k-i-2] * info[i];
            ans += info[k-1];
            for (int i=0; i<=k; ++i)
                cnt[i] += info[i];
        }
    cnt.insert(cnt.begin(), 1);
    cnt.pop_back();
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;

    edges = vector<vector<int>>(n+1, vector<int>{});

    for (int x,y,i=0; i+1<n; ++i) {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    vis = vector<bool>(n+1, false);
    int root = rand() % n + 1;

    dp(root);
    cout << ans << endl;

    return 0;
}