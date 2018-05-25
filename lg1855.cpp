#include <cstdio>
#include <algorithm>

using namespace std;

int a[103], b[103], f[203][203];
int n, m, t;

int main() {
    scanf("%d %d %d", &n, &m, &t);
    for (int i=1; i<=n; ++i) scanf("%d %d", &a[i], &b[i]);

    for (int i=1; i<=n; ++i) 
        for (int j=m; j>=a[i]; j--)
            for (int k=t; k>=b[i]; --k)
                f[j][k] = max(f[j][k], f[j-a[i]][k-b[i]]+1);

    printf("%d\n", f[m][t]);
    return 0;
}