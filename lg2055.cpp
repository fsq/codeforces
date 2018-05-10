#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

#define REP(i,a,b) for (int i=a; i<=(b); ++i)
#define pb push_back

using namespace std;

const int INF = 0x3f3f3f3f;
int n;

bool bfs(vector<int> e[], vector<int>& m, vector<int>& d) {
    queue<int> q;
    d[0] = INF;
    REP(i, 1, n)
        if (m[i])
            d[i] = INF;
        else 
            d[i] = 0, q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (d[u]<d[0])
            for (auto v : e[u])
                if (d[m[v]]==INF) {
                    d[m[v]] = d[u] + 1;
                    q.push(m[v]);
                }
    }
    return d[0] != INF;
}

bool dfs(int u, vector<int> e[], vector<int>& m, vector<int>& d) {
    if (!u) return true;
    int dt = d[u];
    d[u] = INF;
    for (auto v : e[u])
        if (d[m[v]]==dt+1 && dfs(m[v], e, m, d)) {
            m[u] = v, m[v] = u;
            return true;
        }
    return false;
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);

        vector<int> sch(n+1), ret(n+1);
        REP(i, 1, n) scanf("%d", &sch[i]);
        REP(i, 1, n) scanf("%d", &ret[i]);

        vector<int> e[n+1];
        int need = 0;
        REP(i, 1, n) {
            bool link = ! (sch[i] && ret[i]);
            if (link) ++need;
            int r;
            REP(j, 1, n) {
                scanf("%d", &r);
                if (j==i) r = 1;
                if (r && link && sch[j]) e[i].pb(j+n);
            }
        }

        vector<int> m(n<<1 | 1);
        vector<int> d(n+1);

        int matching = 0;
        while (bfs(e, m, d))
            REP(i, 1, n) 
                if (d[i]==0 && dfs(i, e, m, d))
                    ++matching;

        if (matching==need)
            printf("^_^\n");
        else
            printf("T_T\n");

    }
    return 0;
}