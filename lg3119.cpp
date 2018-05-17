#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <numeric>

using namespace std;
const int N = 100007;

vector<int> e[N], et[N], ec[N];
vector<int> fa;
int n, m, f[N], sz[N], id[N];
int vis[N];
int reach[N];

void dfs(int u, vector<int> e[], vector<int>& a, int vis[]) {
    vis[u] = 1;
    for (auto v : e[u])
        if (!vis[v])
            dfs(v, e, a, vis);
    a.push_back(u);
}

int find(int x) { return fa[x]==x ? x : fa[x]=find(fa[x]); }

void coloring(int u, int color[], int c) {
    color[u] = c;
    for (auto v : ec[u])
        if (!color[v])
            coloring(v, color, c);
}

// true if u can reach 1
bool dp(int u) {
    if (reach[u]==1) return true;
    else if (reach[u]==-1) return false;
    reach[u] = -1;
    for (auto v : ec[u])
        if (!vis[v] && dp(v)) {
            reach[u] = 1;
            f[u] = max(f[u], f[v]);
        }
    f[u] += sz[u];
    return reach[u]==1;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int u,v,i=0; i<m; ++i) {
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
        et[v].push_back(u);
    }

    vector<int> ord;
    for (int i=1; i<=n; ++i)
        if (!vis[i])
            dfs(i, e, ord, vis);

    memset(vis, 0, sizeof(vis));
    fa.resize(n+1);
    iota(fa.begin(), fa.end(), 0);
    vector<int> heads;

    for (int i=n-1; i>=0; --i)
        if (!vis[ord[i]]) {
            vector<int> cc;
            dfs(ord[i], et, cc, vis);
            for (auto x : cc) {
                ++sz[ord[i]];
                fa[x] = ord[i];
            }
            heads.push_back(ord[i]);
        }

    for (int u=1; u<=n; ++u)
        for (auto v : e[u])
            if (find(u)!=find(v)) 
                ec[fa[u]].push_back(fa[v]);

    for (int u : heads) {
        sort(ec[u].begin(), ec[u].end());
        ec[u].resize(unique(ec[u].begin(), ec[u].end()) - ec[u].begin());
    }

    int ans = sz[find(1)];
    // split heads into 2 groups
    // 0 : can reach 1
    // 1 : can be reach from 1
    memset(vis, 0, sizeof(vis));
    coloring(find(1), vis, 1);

    // topo dp at the lower part 
    for (auto u : heads)
        for (auto v : ec[u])
            if (vis[u] && vis[v])
                ++id[v];
    queue<int> q;
    q.push(find(1));

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        f[u] += sz[u];
        for (auto v : ec[u]) {
            f[v] = max(f[v], f[u]);
            if (--id[v]==0) 
                q.push(v);
        }
    }
    for (auto v : ec[find(1)]) ans = max(ans, f[v]);

    // topo dp at upper part
    vis[find(1)] = 0;
    reach[find(1)] = 1;
    for (auto u : heads)
        if (!vis[u] && (reach[u]==1 || (!reach[u] && dp(u)))
            && std::find(ec[u].begin(), ec[u].end(), find(1))!=ec[u].end())
                ans = max(ans, f[u]);

    for (auto u : heads)
        for (auto v : ec[u])
            if (reach[u]==1 && vis[v])
                ans = max(ans, f[u]+f[v]-sz[find(1)]);
    printf("%d\n", ans);

    return 0;
}