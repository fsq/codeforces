#include <vector>
#include <algorithm>
#include <cstdio>
#include <numeric>

using namespace std;

vector<int> fa(30007);
vector<int> sz=fa, rk=fa;

int find(int x) {
    if (fa[x]==x) return x;
    int f = fa[x];
    fa[x] = find(fa[x]);
    rk[x] += rk[f];
    return fa[x];
}

int main() {
    fill(sz.begin(), sz.end(), 1);
    iota(fa.begin(), fa.end(), 0);
    int t;
    scanf("%d\n", &t);
    char c;
    int x, y;
    while (t--) {
        scanf("%c %d %d\n", &c, &x, &y);
        int fx=find(x), fy=find(y);
        if (c=='M') {
            fa[fx] = fy;
            rk[fx] = sz[fy];
            sz[fy] += sz[fx];
        } else {
            if (fx!=fy) {
                printf("-1\n");
                continue;
            } else {
                printf("%d\n", abs(rk[x]-rk[y])-1);
            }
        }
    }
    return 0;
}