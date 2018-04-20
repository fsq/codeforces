#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
vector<int> e[10007];
int vis[10007];
int meet[10007];
const int INF = 0x3f3f3f3f;

void fill(int u) {
    meet[u] = 1;
    for (auto v : e[u])
        if (!meet[v])
            fill(v);
}

int dfs(int u, int c) {
    vis[u] = c;
    int cnt = c==1;
    for (auto nxt : e[u])
        if (vis[nxt]==0) {
            int sub = dfs(nxt, -c);
            if (sub==INF) return INF;
            cnt += sub;
        } else if (vis[nxt]==c)
            return INF;
    return cnt;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int u,v,i=0; i<m; ++i) {
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int ans = 0;
    for (int i=1; i<=n; ++i)
        if (!meet[i]) {
            fill(i);
            memset(vis, 0, sizeof(vis));
            int tm = dfs(i, -1);
            memset(vis, 0, sizeof(vis));
            tm = min(tm, dfs(i, 1));
            if (tm==INF) {
                ans = INF;
                break;
            }
            ans += tm;
        }

    if (ans==INF)
        printf("Impossible\n");
    else
        printf("%d\n", ans);

    return 0;
}