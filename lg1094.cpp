#include <cstdio>
#include <algorithm>

using namespace std;

int n, w, a[203];

int main() {
    scanf("%d %d", &w, &n);

    int mn=201, mx=0;
    for (int x,i=0; i<n; ++i) {
        scanf("%d", &x);
        ++a[x];
        mn = min(x, mn);
        mx = max(x, mx);
    }

    int ans = 0;
    for (int i=mx; i>=mn; --i) 
        if (a[i]) {
            for (int j=w-i; j>=mn && a[i]; --j)
                if (a[j]) {
                    int gp = i==j ? a[i]/2 : min(a[i], a[j]);
                    a[i] -= gp;
                    a[j] -= gp;
                    ans  += gp;
                }
            if (a[i]) 
                ans += a[i]; 
        }

    printf("%d\n", ans);
    return 0;
}