#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <numeric>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define PER(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

int n, m;
vector<int> fa, sz, od;
vector<int> e[10007], et[10007];

int find(int x) {
    return fa[x]==x ? x : fa[x]=find(fa[x]);
}

void dfs(int u, vector<int> e[], vector<int>& a, bool vis[]) {
    vis[u] = true;
    for (auto v : e[u])
        if (!vis[v])
            dfs(v, e, a, vis);
    a.push_back(u);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int u,v,i=0; i<m; ++i) {
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
        et[v].push_back(u);
    }

    vector<int> ord;
    bool vis[n+1];
    memset(vis, false, sizeof(vis));
    REP(i, 1, n)
        if (!vis[i])
            dfs(i, e, ord, vis);

    memset(vis, false, sizeof(vis));
    fa.resize(n+1);
    sz.resize(n+1);
    od.resize(n+1);
    iota(fa.begin(), fa.end(), 0);
    PER(i, ord.size()-1, 0)
        if (!vis[ord[i]]) {
            vector<int> cc;
            dfs(ord[i], et, cc, vis);
            for (auto x : cc) {
                fa[x] = ord[i];
                ++sz[ord[i]];
            }
        }

    REP(u, 1, n)
        for (auto v : e[u])
            if (find(u)!=find(v))
                ++od[fa[u]];

    int cand, cnt=0;
    REP(i, 1, n)
        if (find(i)==i && !od[i]) 
            if (++cnt==1)
                cand = i;
            else 
                break;
        else {}

    printf("%d\n", cnt==1 ? sz[cand] : 0);

    return 0;
}