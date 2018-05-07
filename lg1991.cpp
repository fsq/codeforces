#include <vector>
#include <cstdio>
#include <algorithm> 
#include <numeric>
#include <cmath>

using namespace std;

int n, ss;

using PII = pair<int,int>;

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {}
};

vector<PII> a;
vector<int> fa;
vector<Edge> e;

int find(int x) {
    return fa[x]==x ? x : fa[x]=find(fa[x]);
}

int main() {
    scanf("%d %d", &ss, &n);
    a.resize(n+1);
    for (int i=1; i<=n; ++i) scanf("%d %d", &a[i].first, &a[i].second);

    auto dist = [](const PII& a, const PII& b) { 
        return (a.first-b.first)*(a.first-b.first) 
                + (a.second-b.second)*(a.second-b.second);
    };

    for (int i=1; i<=n; ++i)
        for (int j=i+1; j<=n; ++j)
            e.push_back(Edge(i, j, dist(a[i], a[j])));

    fa.resize(n+1);
    iota(fa.begin(), fa.end(), 0);

    sort(e.begin(), e.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    int cc = n;

    for (auto& p : e) {
        int fu = find(p.u), fv = find(p.v);
        if (fu!=fv) {
            fa[fu] = fv;
            if (--cc==ss) {
                printf("%.2f\n", sqrt(p.w));
                break;
            }
        }
    }

    return 0;
}