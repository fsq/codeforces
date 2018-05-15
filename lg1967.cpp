#include <vector>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <climits>

using namespace std;

int n, m;
vector<int> fa;
vector<pair<int,int>> e[10007];
int dp[10007];
pair<int,int> f[10007][15]; // parent, min weight

struct Edge { 
    int u,v,w; 
    Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {}
};

int find(int x) { return fa[x]==x ? x : fa[x]=find(fa[x]); }

void build(int x, int d) {
    dp[x] = d;
    for (int i=1; f[x][i-1].first; ++i) {
        int fa = f[x][i-1].first;
        f[x][i] = {f[fa][i-1].first, min(f[x][i-1].second, f[fa][i-1].second)};
    }
    for (auto p : e[x])
        if (!dp[p.first]) {
            f[p.first][0] = {x, p.second};
            build(p.first, d+1);
        }
}

int main() {
    scanf("%d %d", &n, &m);
    vector<Edge> edge;
    for (int u,v,w,i=0; i<m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        edge.emplace_back(u, v, w);
    }

    sort(edge.begin(), edge.end(), [](const Edge& a, const Edge& b) {
        return a.w > b.w;
    });

    fa.resize(n+1);
    iota(fa.begin(), fa.end(), 0);

    for (int cc=n, i=0; cc>1 && i<edge.size(); ++i) {
        auto& p = edge[i];
        int fx = find(p.u), fy = find(p.v);
        if (fx!=fy) {
            --cc;
            fa[fx] = fy;
            e[p.u].push_back({p.v, p.w});
            e[p.v].push_back({p.u, p.w});
        }
    }

    for (int i=1; i<=n; ++i)
        if (!dp[i])
            build(1, 1);

    int t;
    scanf("%d", &t);
    for (int a, b; t; --t) {
        scanf("%d %d", &a, &b);

        if (find(a)!=find(b)) {
            printf("-1\n");
            continue;
        }

        if (dp[a]<dp[b]) swap(a, b);
        int ans = INT_MAX;

        for (int i=14; dp[a]!=dp[b] && i>=0; --i)
            if (dp[a]-(1<<i)>=dp[b]) {
                ans = min(ans, f[a][i].second);
                a = f[a][i].first;
            }
        for (int i=14; i>=0; --i)
            if (f[a][i].first!=f[b][i].first) {
                ans = min(ans, min(f[a][i].second, f[b][i].second));
                a = f[a][i].first;
                b = f[b][i].first;
            }
        if (a!=b) ans = min(ans, min(f[a][0].second, f[b][0].second));
        printf("%d\n", ans);
    }

    return 0;
}