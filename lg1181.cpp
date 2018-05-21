#include <cstdio>

using namespace std;

int a[100008], n, m;

int main() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; ++i) scanf("%d", &a[i]);
    int ans = 0;
    for (int i=0; i<n; ) {
        for (int s=0; i<n && s+a[i]<=m; s += a[i++]);
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}