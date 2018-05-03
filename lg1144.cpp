#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

vector<int> e[100007];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int x,y,i=0; i<m; ++i) {
        scanf("%d %d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }

    bool vis[n+1]; 
    memset(vis, false, sizeof(vis));

    vector<int> cnt(n+1), dis(n+1, INT_MAX);
    cnt[1] = 1, dis[1] = 0;

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : e[u]) 
            if (dis[v]==INT_MAX) {
                dis[v] = dis[u] + 1;
                vis[v] = true;
                cnt[v] = cnt[u];
                q.push(v);
            } else if (dis[v]==dis[u]+1)
                cnt[v] = (cnt[v] + cnt[u]) % 100003;
    }
    for (int i=1; i<=n; ++i)
        printf("%d\n", cnt[i]);

    return 0;
}