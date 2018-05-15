#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;
vector<int> e[100007];
int vis[100007], sz[100007];
int stamp = 0;
long long cc, ans[100007];

int dfs1(int u) {
    int low = vis[u] = ++stamp;
    long long top=0, c=0, c2=0;
    sz[u] = 1;
    
    for (auto v : e[u]) 
        if (!vis[v]) { 
            int l = dfs1(v);
            sz[u] += sz[v];
            low = min(low, l);
            if (l>=vis[u]) {
                c += sz[v];
                c2 += (long long)sz[v]*sz[v];
            }
            else   
                top += sz[v];
        } else 
            low = min(low, vis[v]);
    
    top += n - sz[u];
    ans[u] = cc - ((n-1)<<1);
    ans[u] -= (top+n-1) * c - c2;

    return low;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int u,v,i=0; i<m; ++i) {
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }

    cc = (long long)n * (n-1);

    dfs1(1);

    for (int i=1; i<=n; ++i)
        printf("%lld\n", (long long)n*(n-1)-ans[i]);
    return 0;
}