#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <numeric>

using namespace std;

struct Edge {
    int u, v;
    double w;
    Edge(int _u, int _v, double _w): u(_u), v(_v), w(_w) {}
};

using PII = pair<int, int>;
vector<PII> a;
vector<Edge> e;
vector<int> fa;

double dist(const PII& a, const PII& b) {
    return sqrt(pow(a.first-b.first, 2) + pow(a.second-b.second, 2));
}

int find(int x) {
    return fa[x]==x ? x : fa[x]=find(fa[x]);
}

int main() {
    int n;
    scanf("%d", &n);

    a.resize(n+1);
    for (int i=1; i<=n; ++i)
        scanf("%d %d", &a[i].first, &a[i].second);

    for (int i=1; i<=n; ++i)
        for (int j=i+1; j<=n; ++j)
            e.push_back(Edge(i, j, dist(a[i], a[j])));

    fa.resize(n+1);
    iota(fa.begin(), fa.end(), 0);

    sort(e.begin(), e.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    double ans = 0;
    for (int cc=n; cc>1; )
        for (auto &p : e) {
            int fu = find(p.u), fv = find(p.v);
            if (fu!=fv) {
                fa[fu] = fv;
                --cc;
                ans += p.w;
            }
        }
    printf("%.2f", round(ans*100)/100);

    return 0;
}