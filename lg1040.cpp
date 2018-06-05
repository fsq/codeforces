#include <cstdio>
#include <algorithm>

using namespace std;

int n;
long long a[37], f[37][37], g[37][37];

void output(int l, int r) {
    if (l>r) 
        return;
    else if (l==r)
        printf("%d ", l);
    else {
        int k = g[l][r];
        printf("%d ", k);
        output(l, k-1), output(k+1, r);
    }
}

long long dp(int l, int r) {
    if (f[l][r]) return f[l][r];
    if (l==r) 
        f[l][r] = a[l];
    else if (l>r)
        f[l][r] = 1;
    else {
        for (int k=l; k<=r; ++k)
            if (f[l][r] < dp(l, k-1)*dp(k+1, r) + a[k]) {
                f[l][r] = f[l][k-1] * f[k+1][r] + a[k];
                g[l][r] = k;
            }
    }
    return f[l][r];
}

int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) scanf("%lld", &a[i]);

    printf("%lld\n", dp(1, n));
    output(1, n);
    printf("\n");
    return 0;
}