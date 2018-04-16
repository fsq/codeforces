#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int w[101], s[101], d[101];

int main() {
    int n, c;
    scanf("%d %d", &n, &c);
    for (int x,i=1; i<=n; ++i) {
        scanf("%d %d", &x, &w[i]);
        d[i] = x;
        s[i] = s[i-1] + w[i];
    }

    int f[101][101][2];

    for (int i=c; i>=1; --i)
        for (int j=c; j<=n; ++j) 
            if (i==j) 
                f[i][j][0] = f[i][j][1] = 0;
            else {
                f[i][j][0] = f[i][j][1] = 0x3f3f3f3f;
                if (i+1<=c)
                f[i][j][0] = min(f[i+1][j][0]+(d[i+1]-d[i])*(s[n]-(s[j]-s[i])), 
                                 f[i+1][j][1]+(d[j]-d[i])*(s[n]-(s[j]-s[i])));
                if (j-1>=c)
                f[i][j][1] = min(f[i][j-1][0]+(d[j]-d[i])*(s[n]-(s[j-1]-s[i-1])),
                                 f[i][j-1][1]+(d[j]-d[j-1])*(s[n]-(s[j-1]-s[i-1])));
            }

    printf("%d\n", min(f[1][n][0], f[1][n][1]));

    return 0;
}