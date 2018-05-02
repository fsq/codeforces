#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
int a[203][203];
int f[203][203][203];

int main() {
    scanf("%d %d", &n, &m);
    vector<int> t(n+1);
    for (int i=1; i<=n; ++i) scanf("%d", &t[i]);

    memset(a, INF, sizeof(a));
    for (int x,y,c,i=1; i<=m; ++i) {
        scanf("%d %d %d", &x, &y, &c);
        ++x, ++y;
        a[x][y] = a[y][x] = c;
    }

    for (int i=1; i<=n; ++i) {
        f[i][i][0] = 0;
        for (int j=i+1; j<=n; ++j)
            f[i][j][0] = f[j][i][0] = a[i][j];
    }

    for (int k=1; k<=n; ++k) 
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=n; ++j)
                f[i][j][k] = min(f[i][j][k-1], f[i][k][k-1] + f[k][j][k-1]);

    int q;
    scanf("%d", &q);
    while (q--) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        ++x, ++y;
        if (t[x]>c || t[y]>c) {
            printf("-1\n");
            continue;
        }
        int k = upper_bound(t.begin(), t.end(), c) - t.begin() - 1;
        printf("%d\n", f[x][y][k]==INF ? -1 : f[x][y][k]);
    }
    return 0;
}