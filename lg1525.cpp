#include <vector>
#include <algorithm>
#include <cstdio>
#include <numeric>

using namespace std;

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {}
};

int n, m;
vector<int> fa, r;
vector<Edge> e;

int find(int x) {
    if (fa[x]==x) return x;
    int t = fa[x];
    fa[x] = find(fa[x]);
    r[x] ^= r[t];
    return fa[x];
}

int main() {
    scanf("%d %d", &n, &m);
    fa = r = vector<int>(n+1);
    iota(fa.begin(), fa.end(), 0);

    for (int u,v,w,i=0; i<m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        e.emplace_back(u, v, w);
    }

    sort(e.begin(), e.end(), [](const Edge& a, const Edge& b) {
        return a.w > b.w;
    });

    int ans = 0;
    for (auto& p : e) {
        int fu = find(p.u), fv = find(p.v);
        if (fu==fv) 
            if (!(r[p.u]^r[p.v])) {
                ans = p.w;
                break;
            } else {}
        else {
            fa[fu] = fv;
            r[fu] = 1 ^ r[p.v] ^ r[p.u];
        }
    }

    printf("%d\n", ans);

    return 0;
}