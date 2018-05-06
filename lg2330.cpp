#include <vector>
#include <cstdio>
#include <numeric>
#include <algorithm>

using namespace std;

int n, m;
struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w):u(_u), v(_v), w(_w) {}
};

vector<Edge> e;
vector<int> fa;

int find(int x) { return fa[x]==x ? x : fa[x]=find(fa[x]); }

int main() {
    scanf("%d %d", &n, &m);
    fa = vector<int>(n+1, 0);
    iota(fa.begin(), fa.end(), 0);
    for (int u,v,w,i=0; i<m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        e.push_back(Edge(u, v, w));
    }

    sort(e.begin(), e.end(), [](const Edge& e1, const Edge& e2) {
        return e1.w < e2.w;
    });

    int mx = 0, chs = 0;
    for (auto& p : e) {
        int fu = find(p.u), fv = find(p.v);
        if (fu != fv) {
            fa[fu] = fv;
            mx = max(mx, p.w);
            if (++chs==n-1) break;
        }
    }

    printf("%d %d\n", n-1, mx);

    return 0;
}