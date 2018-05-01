#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

const int MAXN = 107;
vector<pair<int,int>> e[MAXN];

int main() {
    int n, s, t;
    scanf("%d %d %d", &n, &s, &t);

    for (int k,j,i=1; i<=n; ++i) {
        scanf("%d", &k);
        if (k==0) continue;
        scanf("%d", &j);
        e[i].push_back({j, 0});
        for (int _t=1; _t<k; ++_t) {
            scanf("%d", &j);
            e[i].push_back({j, 1});
        }
    }

    vector<int> d(n+1, INT_MAX);
    bool done[n+1];
    memset(done, false, sizeof(done));
    d[s] = 0;
    for (int _t=1; _t<=n; ++_t) {
        int mind = INT_MAX, u = -1;
        for (int i=1; i<=n; ++i)
            if (!done[i] && d[i]<mind) {
                mind = d[i];
                u = i;
            }

        if (u==-1 || u==t) break;
        done[u] = true;

        for (auto &p : e[u])
            if (!done[p.first] && d[u]+p.second<d[p.first])
                d[p.first] = d[u] + p.second;
    }
    printf("%d\n", d[t]==INT_MAX ? -1 : d[t]);
    return 0;
}