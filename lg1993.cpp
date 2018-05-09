#include <vector>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cstring>

using namespace std;

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {}
};

int n, m;
const int INF = 0x3f3f3f3f;
vector<Edge> e[10007];
int d[10007];
bool vis[10007];

bool spfa(int x) {
    vis[x] = true;
    for (auto& p : e[x])
        if (d[x]+p.w<d[p.v]) {
            d[p.v] = d[x] + p.w;
            if (vis[p.v] || spfa(p.v))
                return true;
        }
    vis[x] = false;
    return false;
}

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int code, a, b, c;
        scanf("%d", &code);
        if (code!=3) {
            scanf("%d %d %d", &a, &b, &c);
            if (code==1)
                e[b].push_back(Edge(b, a, -c));
            else 
                e[a].push_back(Edge(a, b, c));
        } else {
            scanf("%d %d", &a, &b);
            e[a].push_back(Edge(a, b, 0));
            e[b].push_back(Edge(b, a, 0));
        }
    }

    memset(d, 0x3f, sizeof(d));
    for (int i=1; i<=n; ++i)
        if (d[i]==INF) {
            d[i] = 0;
            if (spfa(i)) {
                printf("No\n");
                return 0;   
            }
        }
    printf("Yes\n");

    return 0;
}