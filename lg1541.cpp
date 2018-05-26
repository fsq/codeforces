#include <cstdio>
#include <algorithm>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int n, m, a[5], f[42][42][42][42], s[400];

int main() {
    scanf("%d %d", &n, &m);

    REP(i, 0, n-1) scanf("%d", &s[i]);

    for (int x,i=1; i<=m; ++i) {
        scanf("%d", &x);
        ++a[x];
    }

    REP(i, 0, a[1]) REP(j, 0, a[2]) REP(k, 0, a[3]) REP(l, 0, a[4]) {
        int &x = f[i][j][k][l];
        if (i) x = f[i-1][j][k][l];
        if (j) x = max(x, f[i][j-1][k][l]);
        if (k) x = max(x, f[i][j][k-1][l]);
        if (l) x = max(x, f[i][j][k][l-1]);
        x += s[i+2*j+3*k+4*l];
    }

    printf("%d\n", f[a[1]][a[2]][a[3]][a[4]]);

    return 0;
}