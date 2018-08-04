#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;

int n, m, s;
vector<pair<int,int>> e[100003];

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

    set<pair<int,int>> h;
    for (auto &nxt : e[s]) 
        if (nxt.first != s) {
            h.insert({nxt.second, nxt.first});
            dis[nxt.first] = min(dis[nxt.first], nxt.second);
        }

    for (int t=2; t<=n; ++t) {
        while (!h.empty() && vis[h.begin()->second])
            h.erase(h.begin());
        if (h.empty()) break;
        int id = h.begin()->second;
        vis[id] = 1;
        for (auto& nxt : e[id])
            if (!vis[nxt.first] && dis[id]+nxt.second<dis[nxt.first]) {
                dis[nxt.first] = dis[id] + nxt.second;
                h.insert({dis[nxt.first], nxt.first});
            }
    }
    for (int i=1; i<=n; ++i) cout << dis[i] << ' ';
    cout << endl;
    return 0;
}