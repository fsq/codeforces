#include <cstdio>
#include <algorithm>
#define REP(i,a,b) for (int i=(a); i<=(b); ++i)

using namespace std;

int n, a[203], f[203][203];

int main() {
    scanf("%d", &n);
    REP(i, 0, n-1) scanf("%d", &a[i]);
    REP(i, n, (n<<1)) a[i] = a[i-n];

    REP(l, 2, n)
        REP(i, 0, (n<<1)-l) {
            int j = i + l - 1;
            REP(k, i, j-1) 
                f[i][j] = max(f[i][j], f[i][k]+f[k+1][j]+a[i]*a[k+1]*a[j+1]);
        }

    int ans = 0;
    REP(i, 0, n-1) ans = max(f[i][i+n-1], ans);
    printf("%d\n", ans);

    return 0;
}