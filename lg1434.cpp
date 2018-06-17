#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int a[105][105], n, m, ans = 0, f[105][105];
bool vis[105][105];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y) {
    vis[x][y] = true;
    f[x][y] = 1;
    for (int dir=0; dir<4; ++dir) {
        int tx=x+dx[dir], ty=y+dy[dir];
        if (tx>0 && tx<=n && ty>0 && ty<=m && a[tx][ty]<a[x][y]) {
            if (!vis[tx][ty]) dfs(tx, ty);
            f[x][y] = max(f[x][y], f[tx][ty]+1);
        }
    }

    ans = max(ans, f[x][y]);
}



int main() {
    cin >> n >> m;

    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j) 
            cin >> a[i][j];


    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            dfs(i, j);

    cout << ans << endl;

    return 0;
}