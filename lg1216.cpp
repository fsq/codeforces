#include <cstdio>
#include <algorithm>

using namespace std;

int f[1003];

int main() {
    int n, t;
    scanf("%d", &n);
    for (int pre=0,i=1; i<=n; ++i) {
        for (int c,j=0; j+1<i; ++j) {
            scanf("%d", &t);
            c = f[j];
            f[j] = max(pre, f[j]) + t;
            pre = c;
        }
        scanf("%d", &t);
        f[i-1] = i>=2 ? pre + t : t;
    }
    int ans = *max_element(f, f+n);
    printf("%d\n", ans);
    return 0;
}