#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> fa;

int find(int x) {
    return fa[x]==x ? x : fa[x]=find(fa[x]);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n+1][n+1];
    vector<vector<int>> e;
    for (int i=1; i<=n; ++i) 
        for (int j=1; j<=n; ++j) {
            scanf("%d", &a[i][j]);
            if (j>i) e.push_back({a[i][j], i, j});
        }

    fa.resize(n+1);
    iota(fa.begin(), fa.end(), 0);

    sort(e.begin(), e.end());

    int ans = 0;
    for (auto& p : e) {
        int l = p[0], u = p[1], v = p[2];
        int fu = find(u), fv = find(v);
        if (fu!=fv) {
            fa[fu] = fv;
            ans += l;
        }
    }

    printf("%d\n", ans);

    return 0;
}