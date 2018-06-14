#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
#define REP(i, a, b) for (int i=(a);i<=(b);++i)

using namespace std;

int n, m, k, s;
vector<int> e[100007];
int color[100007];
int dis[100007][103];
bool vis[100007];

void bfs(int c) {
    memset(vis, false, sizeof(vis));
    queue<int> q;
    REP(i, 1, n) 
        if (color[i]==c) {
            dis[i][c] = 0;
            q.push(i);
            vis[i] = true;
        } else 
            dis[i][c] = INT_MAX;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : e[u])
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
                dis[v][c] = dis[u][c] + 1;
            }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k >> s;
    REP(i, 1, n) cin >> color[i];

    for (int u,v,i=0; i<m; ++i) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    REP(c, 1, k) bfs(c);
    
    REP(i, 1, n) {
        sort(dis[i]+1, dis[i]+k+1);
        int d = 0;
        REP(j, 1, s) d += dis[i][j];
        cout << d << ' ';
    }
    cout << endl;

    return 0;
}