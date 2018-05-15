#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 101;

int n, m;
int f[N][131][N];
int d[N][N];

int main() {
    scanf("%d %d", &n, &m);
    for (int u,v,i=0; i<m; ++i) {
        scanf("%d %d", &u, &v);
        d[u][v] = 1;
        f[u][0][v] = 1;
    }

    for (int p=1; p<70; ++p) 
        for (int u=1; u<=n; ++u) 
            for (int x=1; x<=n; ++x)
                if (f[u][p-1][x])
                    for (int v=1; v<=n; ++v)
                        if (f[x][p-1][v]) {
                            f[u][p][v] = 1;
                            d[u][v] = 1;
                        }

    bool vis[n+1];
    memset(vis, false, sizeof(vis));
    vis[1] = true;
    queue<pair<int,int>> q;
    q.push({1, 0});

    int ans;
    while (!q.empty()) {
        int u = q.front().first, l = q.front().second; 
        q.pop();
        for (int i=1; i<=n; ++i)
            if (d[u][i]==1 && !vis[i]) {
                vis[i] = true;
                if (i==n) {
                    ans = l + 1;
                    break;
                } else 
                    q.push({i, l+1});
            }
    }
    printf("%d\n", ans);

    return 0;
}