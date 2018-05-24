#include <algorithm>
#include <cstdio>

using namespace std;

int n, m, f[55][55][55], a[55][55];

int dp(int x, int y, int x1) {
    int y1 = x+y - x1;

    if (x<1 || x>n || y<1 || y>m) return 0;
    if (x1<1 || x1>n || y1<1 || y1>m) return 0;
    if (x<=x1) return 0;
    if (f[x][y][x1]) return f[x][y][x1];
    
    int& ret = f[x][y][x1];
    ret = max(max(dp(x-1,y,x1), dp(x-1,y,x1-1)), max(dp(x,y-1,x1), dp(x,y-1,x1-1)));
    ret += a[x][y] + a[x1][y1];
    return ret;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            scanf("%d", &a[i][j]);
    printf("%d\n", dp(n, m-1, n-1));
    return 0;
}