#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int a[203][203], f[203][203], n, m;
bool vis[203][203];

int dp(int x, int y) {
    if (x==n+1) return y==((m+1)>>1) ? 0 : INT_MIN;
    if (vis[x][y]) return f[x][y];
    vis[x][y] = true;
    f[x][y] = dp(x+1, y)==INT_MIN ? INT_MIN : f[x+1][y]+a[x][y];
    if (y>1 && dp(x+1, y-1)!=INT_MIN) f[x][y] = max(f[x][y], f[x+1][y-1]+a[x][y]);
    if (y<m && dp(x+1, y+1)!=INT_MIN) f[x][y] = max(f[x][y], f[x+1][y+1]+a[x][y]);
    return f[x][y];
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            scanf("%d", &a[i][j]);

    int ans = dp(1, 1);
    for (int i=2; i<=m; ++i) ans = max(ans, dp(1, i));
    printf("%d\n", ans);
    return 0;
}