#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;
const int MAXN = 3007;
const int INF = -0x3f3f3f3f;

vector<pair<int,int>> e[MAXN]; // node, cost
int sz[MAXN]; // # of users in subtree
int f[MAXN][MAXN];
int pay[MAXN];

int mark_size(int x) {
    if (x>n-m) return sz[x]=1;
    for (auto& nxt : e[x])
        sz[x] += mark_size(nxt.first);
    return sz[x];
}

void dp(int x) {
    if (x>n-m) 
        f[x][0] = 0, f[x][1] = pay[x];
    else {
        fill(f[x], f[x]+sz[x]+1, INF);
        f[x][0] = 0;
        for (auto& pr : e[x]) {
            dp(pr.first);
            for (int i=sz[x]; i>=1; --i) 
                for (int k=1; k<=sz[pr.first]; ++k)
                    if (i-k>=0 && f[x][i-k]!=INF)
                        f[x][i] = max(f[x][i], f[x][i-k]+f[pr.first][k]-pr.second);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int k,i=1; i<=n-m; ++i) {
        scanf("%d", &k);
        for (int a,c,j=1; j<=k; ++j) {
            scanf("%d %d", &a, &c);
            e[i].push_back({a,c});
        }
    }
    for (int i=n-m+1; i<=n; ++i) scanf("%d", &pay[i]);

    mark_size(1);

    dp(1);

    for (int i=sz[1]; i>=0; --i)
        if (f[1][i]>=0) {
            printf("%d\n", i);
            break;
        }

    return 0;
}