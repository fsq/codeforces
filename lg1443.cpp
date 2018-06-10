#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

int n, m, x, y;
bool vis[405][405];
int a[405][405];

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1,-1, -2, -2, -1};

int main() {
    scanf("%d %d %d %d", &n, &m, &x, &y);
    queue<pair<int,int>> q;
    q.push({x, y});

    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            a[i][j] = -1;
    a[x][y] = 0;
    vis[x][y] = true;

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i=0; i<8; ++i) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx>=1 && tx<=n && ty>=1 && ty<=m && !vis[tx][ty]) {
                a[tx][ty] = a[x][y] + 1;
                vis[tx][ty] = true;
                q.push({tx, ty});
            }
        }
    }

    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) printf("%-5d", a[i][j]);
        printf("\n");
    }

    return 0;
}