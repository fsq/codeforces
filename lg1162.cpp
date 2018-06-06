#include <cstdio>
#include <algorithm>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)

using namespace std;

int n;
int a[35][35];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(int x, int y) {
    a[x][y] = 2;
    for (int dir=0; dir<4; ++dir) {
        int tx = x+dx[dir], ty = y+dy[dir];
        if (tx>0 && tx<=n && ty>0 && ty<=n && !a[tx][ty]) 
            dfs(tx, ty);
    }
}

int main() {
    scanf("%d", &n);
    REP(i, 1, n) REP(j, 1, n) scanf("%d", &a[i][j]);

    REP(i, 1, n) 
        if (!a[1][i]) dfs(1, i);
    REP(i, 2, n-1) {
        if (!a[i][1]) dfs(i, 1);
        if (!a[i][n]) dfs(i, n);
    }
    REP(i, 1, n)
        if (!a[n][i]) dfs(n, i);

    REP(i, 1, n) {
        REP(j, 1, n) 
            printf("%d ", -a[i][j] + 2);
        printf("\n");
    }

    return 0;
}