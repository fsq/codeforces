#include <cstdio>
#include <vector>
#include <queue>

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

    priority_queue<PII, vector<PII>, greater<PII>> q;
    vector<int> d(n+1, INF);
    d[s] = 0;
    for (auto& p : e[s]) q.push(p);
    REP(_t, 1, n-1) {
        while (d[q.top().second]!=INF) q.pop();

        int u = q.top().second, w = q.top().first;
        d[u] = w;
        q.pop();

        if (u==t) break;

        for (auto & p : e[u])
            if (d[p.second]==INF)
                q.push({w+p.first, p.second});
    }

    printf("%d\n", d[t]);

    return 0;
}