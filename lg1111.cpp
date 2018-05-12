#include <vector>
#include <algorithm>
#include <cstdio>
#include <numeric>

using namespace std;

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w):u(_u),v(_v),w(_w) {}
};
vector<Edge> e;
vector<int> fa;

int find(int x) {
    return fa[x]==x ? x : fa[x]=find(fa[x]);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int u,v,w,i=1; i<=m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        e.push_back(Edge(u, v, w));
    }

    sort(e.begin(), e.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    fa.resize(n+1);
    iota(fa.begin(), fa.end(), 0);
    int cc = n, ans = 0;

    for (auto& p : e) {
        int fu = find(p.u), fv = find(p.v);
        if (fu!=fv) {
            fa[fu] = fv;
            ans = p.w;
            if (--cc==1) break;
        }
    }

    printf("%d\n", cc==1 ? ans : -1);

    return 0;
}