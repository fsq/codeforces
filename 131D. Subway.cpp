#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> edges;
vector<pair<int,int>> es;
int n;

int find(vector<int>& fa, int x) {
    return fa[x]==x ? x : fa[x]=find(fa,fa[x]);
}

bool dfs(vector<int>& path, vector<bool>& vis, int now, int start, int aim) {
    path.push_back(now);
    vis[now] = true;

    if (now==aim) return true;

    for (auto nxt : edges[now])
        if (!(now==start && nxt==aim || now==aim && nxt==start) 
            && !vis[nxt] && dfs(path, vis, nxt, start, aim))
            return true;

    path.pop_back();
    return false;
}

vector<int> find_loop() {
    vector<int> fa = {0};
    for (int i=1; i<=n; ++i) fa.push_back(i);

    // union set find extra edge
    int xl, yl;
    bool found = false;
    for (auto& edge: es) {
        int x = edge.first, y = edge.second;
        int fx = find(fa, x), fy = find(fa, y);
        if (fx==fy) {
            xl = x;
            yl = y;
            found = true;
            break;
        } else 
            fa[fx] = fy;
        if (found) break;
    }

    // dfs find loop
    vector<int> path;
    vector<bool> vis(n+1, false);
    dfs(path, vis, xl, xl, yl);

    return path;
}

void dfs1(vector<int>& dis, int now, int len) {
    dis[now] = len;
    for (auto nxt : edges[now])
        if (dis[nxt]==INT_MAX)
            dfs1(dis, nxt, len+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;

    edges = vector<vector<int>>(n+1, vector<int>{});
    for (int x,y,i=0; i<n; ++i) {
        cin >> x >> y;
        es.push_back({x, y});
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    auto loop = find_loop();

    vector<int> dis(n+1, INT_MAX);
    for (auto station : loop) 
        dis[station] = 0;

    // dfs find distance
    for (auto station : loop) 
        for (auto nxt : edges[station])
            if (dis[nxt] != 0)
                dfs1(dis, nxt, 1);
    
    for (int i=1; i<n; ++i)
        cout << dis[i] << ' ';
    cout << dis.back() << endl;

    return 0;
}