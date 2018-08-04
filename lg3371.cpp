#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, m, s;
vector<pair<int,int>> e[10001];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> s;
    for (int u,v,w,i=0; i<m; ++i) {
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }

    vector<int> vis(n+1), dis(n+1, INT_MAX);
    dis[s] = 0;
    vis[s] = 1;
    for (auto &nxt : e[s]) dis[nxt.first] = min(dis[nxt.first], nxt.second);
    for (int t=2; t<=n; ++t) {
        int mind=INT_MAX, id=0;
        for (int i=1; i<=n; ++i)
            if (!vis[i] && dis[i]<mind) {
                mind = dis[i];
                id = i;
            }
        if (mind==INT_MAX) break;
        vis[id] = true;
        for (auto& nxt : e[id])
            if (!vis[nxt.first])
                dis[nxt.first] = min(dis[nxt.first], dis[id]+nxt.second);
    }
    for (int i=1; i<=n; ++i) cout << dis[i] << ' ';
    cout << endl;
    return 0;
}