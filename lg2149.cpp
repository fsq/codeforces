#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#define REP(i,a,b) for(int i=(a); i<=(b); ++i)
#define PB push_back
using namespace std;

int n, m;
const int N = 1507;
const int INF = 0x3f3f3f3f;
int s1, t1, s2, t2;

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w):u(_u), v(_v), w(_w) {}
};

vector<int> dij(int s, vector<Edge> e[]) {
    vector<int> d(n+1, INF);
    d[s] = 0;
    bool vis[n+1];
    memset(vis, false, sizeof(vis));
    vis[s] = true;
    for (auto& p : e[s]) d[p.v] = p.w;
    REP(_t, 1, n-1) {
        int mind = INF, u;
        REP(i, 1, n)
            if (!vis[i] && d[i]<mind) {
                mind = d[i];
                u = i;
            }
        if (mind==INF) break;
        vis[u] = true;
        for (auto& p : e[u])
            if (d[u]+p.w<d[p.v]) 
                d[p.v] = d[u] + p.w;
    }
    return d;
}

pair<vector<vector<Edge>>, vector<int>>
build(vector<Edge> e[], const vector<int>& ds1, const vector<int>& ds2, 
            const vector<int>& dt1, const vector<int>& dt2) {
    vector<vector<Edge>> g(n+1, vector<Edge>());
    vector<int> ind(n+1);
    REP(u, 1, n) 
        for (auto &p : e[u]) {
            int v = p.v;
            if (ds1[u]+p.w+dt1[v]==ds1[t1]) {
                int w = (ds2[u]+p.w+dt2[v]==ds2[t2] || ds2[v]+p.w+dt2[u]==ds2[t2])
                        ? p.w : 0;
                g[u].PB(Edge(u, v, w));
                // printf("g:%d %d %d\n", u,v,w);
                ++ind[v];
            }
        }
    return {g, ind};
}

int main() {
    scanf("%d %d %d %d %d %d", &n, &m, &s1, &t1, &s2, &t2);
    vector<Edge> e[n+1];
    REP(i, 1, m) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        e[u].PB(Edge(u, v, w));
        e[v].PB(Edge(v, u, w));
    }

    auto ds1 = dij(s1, e);
    auto ds2 = dij(s2, e);
    auto dt1 = dij(t1, e);
    auto dt2 = dij(t2, e);

    // printf("%d %d\n", ds1[t1], ds2[t2]);

    pair<vector<vector<Edge>>, vector<int>> G = build(e, ds1, ds2, dt1, dt2);

    auto& g = G.first;
    auto& ind = G.second;
    vector<int> f(n+1);
    queue<int> q;
    REP(i, 1, n) 
        if (!ind[i])
            q.push(i);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto& p : g[u]) {
            f[p.v] = max(f[p.v], f[u]+p.w);
            if (--ind[p.v]==0)
                q.push(p.v);
        }
    }

    printf("%d\n", f[t1]);

    return 0;
}