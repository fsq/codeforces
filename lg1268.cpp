#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

int a[51][51];
bool com[51];

int main() {
    for (int n; ; ) {
        scanf("%d", &n);
        if (n==0) break;

        memset(a, 0, sizeof(a));
        for (int i=1; i<n; ++i)
            for (int j=i+1; j<=n; ++j) {
                scanf("%d", &a[i][j]);
                a[j][i] = a[i][j];
            }

        int ans = 0;
        memset(com, true, sizeof(com));
        for (int cc=n; cc>1; --cc) {
            bool found = false;
            for (int i=1; i<=n; ++i)
                if (com[i]) {
                    for (int j=i+1; j<=n; ++j) {
                        if (com[j]) {
                            int gp = INT_MAX;
                            bool valid = true;
                            for (int k=1; k<=n; ++k)
                                if (k!=i && k!=j && com[k]) 
                                    if (gp==INT_MAX)
                                        gp = a[i][k] - a[j][k];
                                    else if (gp!=a[i][k]-a[j][k]) {
                                        valid = false;
                                        break;
                                    } else {}
                                else {}
                            if (valid) {
                                int d = a[i][j];
                                ans += d;
                                com[j] = false;
                                for (int k=1; k<=n; ++k)
                                    if (k!=i && k!=j && com[k])
                                        a[k][i] = a[i][k] 
                                                = (a[i][k]+a[j][k]-d)>>1;
                                found = true;
                            }
                        }
                        if (found) break;
                    }
                    if (found) break;
                }
        }


        printf("%d\n", ans);
    }
    return 0;
}