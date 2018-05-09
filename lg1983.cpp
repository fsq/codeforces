#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 1005;
int a[N][N];
int f[N];
int n, m;

int dp(int x) {
    if (f[x]!=0) return f[x];
    f[x] = 1;
    for (int y=1; y<=n; ++y)
        if (a[x][y])
            f[x] = max(f[x], dp(y)+1);
    return f[x];
}

int main() {
    scanf("%d %d", &n, &m);
    for (int n,i=0; i<m; ++i) {
        vector<int> s;
        scanf("%d", &n);
        for (int x, j=0; j<n; ++j) {
            scanf("%d", &x);
            s.push_back(x);
        }

        vector<int> t;
        for (int i=s.front()+1; i<s.back(); ++i)
            if (*lower_bound(s.begin(), s.end(), i)!=i) 
                t.push_back(i);

        for (auto x : s)
            for (auto y : t)
                a[x][y] = 1;
    }

    int ans = 0;
    for (int i=1; i<=n; ++i)
        ans = max(ans, dp(i));

    printf("%d\n", ans);
    return 0;
}