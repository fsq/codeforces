#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int n;
const int MAXN = 200007;
vector<int> e[MAXN], et[MAXN];
bool vis[MAXN];

void dfs(int u, vector<int> e[], vector<int>& a) {
    vis[u] = true;
    for (auto nxt : e[u])
        if (!vis[nxt]) dfs(nxt, e, a);
    a.push_back(u);
}

int main() {
    scanf("%d", &n);

    for (int j,i=1; i<=n; ++i) {
        scanf("%d", &j);
        e[i].push_back(j);
        et[j].push_back(i);
    }


    vector<int> ord;
    for (int i=1; i<=n; ++i)
        if (!vis[i])
            dfs(i, e, ord);
    int ans = n;
    memset(vis, false, sizeof(vis));
    for (int i=ord.size()-1; i>=0; --i)
        if (!vis[ord[i]]) {
            vector<int> scc;
            dfs(ord[i], et, scc);
            if (scc.size()>1) ans = min<int>(ans, scc.size());
        }

    printf("%d\n", ans);

    return 0;
}