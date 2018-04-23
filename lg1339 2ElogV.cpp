#include <cstdio>
#include <vector>
#include <queue>
#include <set>

#define REP(i,a,b) for (int i=(a);i<=(b);++i)
#define PB push_back
using namespace std;

using PII = pair<int,int>;
const int MAXN = 3007;
const int INF = 0x3f3f3f3f;

vector<PII> e[MAXN];
int n,m, s, t;

int main() {
    scanf("%d %d %d %d", &n, &m, &s, &t);
    REP(i, 1, m) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        e[u].PB({w, v});
        e[v].PB({w, u});
    }

    set<PII> q;
    vector<int> d(n+1, INF);
    d[s] = 0;

    q.insert({0, s});
    REP(i, 1, n) if (i!=s) q.insert({INF, i});

    REP(_t, 1, n-1) {
        int u = q.begin()->second, w = q.begin()->first;

        q.erase(q.begin());
        d[u] = w;
        if (u==t) break;

        for (auto& p : e[u])
            if (w+p.first<d[p.second]) {
                q.erase({d[p.second], p.second});
                d[p.second] = w + p.first;
                q.insert({d[p.second], p.second});
            }
    }

    printf("%d\n", d[t]);

    return 0;
}