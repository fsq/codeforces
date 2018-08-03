#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

class Edge {
public:
    int u, v, w;
    Edge(int u, int v, int w):u(u),v(v),w(w) {}
};

vector<int> fa;

int find(int x) { return fa[x]==x ? x : fa[x]=find(fa[x]); }

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    vector<Edge> e;
    for (int u,v,w,i=0; i<m; ++i) {
        cin >> u >> v >> w;
        e.push_back(Edge(u, v, w));
    }

    sort(e.begin(), e.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    fa.resize(n+1);
    iota(fa.begin(), fa.end(), 0);
    int ans = 0;
    for (auto& edge : e) {
        int fx=find(edge.u), fy=find(edge.v);
        if (fx!=fy) {
            fa[fx] = fy;
            ans += edge.w;
        }
    }

    cout << ans << endl;
    return 0;
}