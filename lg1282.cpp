#include <vector>
#include <cstdio>
#include <cstring>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)

using namespace std;
using VI = vector<int>;

int f[1003][12005];

const int INF = 0x3f3f3f3f;

int main() {
    int n;
    scanf("%d", &n);
    VI a(n+1), b=a;

    REP(i, 1, n) scanf("%d %d", &a[i], &b[i]);

    memset(f, 0x3f, sizeof(f));
    f[0][5*n] = 0;
    REP(i, 1, n) 
        REP(j, -5*i, 5*i) {
            int c = j+5*n;
            if (f[i-1][c-(a[i]-b[i])]!=INF)
                f[i][c] = f[i-1][c-(a[i]-b[i])];
            if (f[i-1][c-(b[i]-a[i])]!=INF)
                f[i][c] = min(f[i][c], f[i-1][c-(b[i]-a[i])]+1);
            // printf("%d %d %d\n", i, j, f[i][c]);
        }
    int ans = 0;
    REP(j, 0, 5*n) 
        if (f[n][j+5*n]!=INF || f[n][-j+5*n]!=INF) {
            // printf("%d\n", j);
            ans = min(f[n][j+5*n], f[n][-j+5*n]);
            break;
        }
    printf("%d\n", ans);

    return 0;
}