#include <vector>
#include <iostream>
#include <string>

using namespace std;

int n, m;
int a[1005][1005], vis[1005][1005], f[1005][1005];

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void dfs(int x, int y, int& cnt) {
    ++cnt;
    vis[x][y] = 1;
    for (int dir=0; dir<4; ++dir) {
        int tx = x + dx[dir], ty = y + dy[dir];
        if (tx>0 && tx<=n && ty>0 && ty<=n && !vis[tx][ty] && (a[tx][ty]^a[x][y])) 
            dfs(tx, ty, cnt);
    }
}

void fill(int x, int y, int cnt) {
    f[x][y] = cnt;
    vis[x][y] = 2;
    for (int dir=0; dir<4; ++dir) {
        int tx = x + dx[dir], ty = y + dy[dir];
        if (vis[tx][ty]==1)
            fill(tx, ty, cnt);
    }
}

int main() {
    cin >> n >> m;
    string s;
    for (int i=1; i<=n; ++i) {
        cin >> s;
        for (int j=0; j<s.size(); ++j) a[i][j+1] = s[j] - '0';
    }

    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)  
            if (!vis[i][j]) {
                int cnt = 0;
                dfs(i, j, cnt);
                fill(i, j, cnt);
            }

    for (int i,j; m; --m) {
        cin >> i >> j;
        cout << f[i][j] << '\n';
    }
    
    return 0;
}