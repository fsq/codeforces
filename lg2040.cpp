#include <vector>
#include <algorithm>
#include <cstdio>
#include <numeric>

using namespace std;

vector<int> fa, r;

int find(int x) {
    if (fa[x]==x) return x;
    int f = fa[x];
    fa[x] = find(fa[x]);
    r[x] = (r[f] + r[x] + 3) % 3;
    return fa[x];
}

int main() {
    int n, m, ans = 0;
    scanf("%d %d", &n, &m);

    fa.resize(n+1);
    iota(fa.begin(), fa.end(), 0);
    r.resize(n+1);

    for (int t,a,b,i=0; i<m; ++i) {
        scanf("%d %d %d", &t, &a, &b);
        if (a>n || b>n) {
            ++ans;
            continue;
        }
        int fx = find(a), fy = find(b);
        if (fx==fy) {
            int rl = (r[b] - r[a] + 3) % 3;
            if (rl+1 != t) ++ans;
        } else {
            fa[fy] = fx;
            r[fy] = (r[a] + (t-1) + 3 - r[b]) % 3;
        }
    }
    printf("%d\n", ans);
    return 0;
}