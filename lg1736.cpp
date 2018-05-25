#include <cstdio>
#include <algorithm>
#define REP(i,a,b) for (int i=(a);i<=(b);++i)
#define PER(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
const int N = 2507;

int up[N][N], le[N][N], ri[N][N], f[N][N], g[N][N];
bool a[N][N];
int n, m, t;

int main() {
    scanf("%d %d", &n, &m);
    REP(i, 1, n) REP(j, 1, m) scanf("%d", &t), a[i][j] = t==1;

    REP(i, 1, n) {
        REP(j, 1, m) {
            up[i][j] = (i==1 || a[i-1][j]) ? 0 : up[i-1][j] + 1;
            le[i][j] = (j==1 || a[i][j-1]) ? 0 : le[i][j-1] + 1;
        }
        PER(j, m, 1) 
            ri[i][j] = (j==m || a[i][j+1]) ? 0 : ri[i][j+1] + 1;
    }

    REP(j, 1, m) f[1][j] = g[1][j] = a[1][j];

    int ans = any_of(a[1]+1, a[1]+m+1, [](int x) { return x==1; });
    REP(i, 2, n) REP(j, 1, m) 
        if (a[i][j]) {
            f[i][j] = j==m ? 1 : min(min(up[i][j], ri[i][j]), f[i-1][j+1]) + 1;
            g[i][j] = j==1 ? 1 : min(min(up[i][j], le[i][j]), g[i-1][j-1]) + 1;
            ans = max(ans, max(f[i][j], g[i][j]));
        }

    printf("%d\n", ans);
    return 0;
}