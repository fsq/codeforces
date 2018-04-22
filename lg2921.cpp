#include <vector>
#include <cstdio>
#define REP(i,a,b) for (int i=(a); i<=(b); ++i)

using namespace std;

const int MAXN = 1e5 + 7;
int n, cnt;
int e[MAXN], d[MAXN];
int vis[MAXN];
int color[MAXN];

// earlies timestamp u can reach
int dfs(int u) {
    color[u] = 1;
    vis[u] = ++cnt;
    int v = e[u], low;
    if (color[v]==0) {
        low = dfs(v);
        if (low<=vis[u])
            d[u] = d[v];
        else 
            d[u] = d[v]+1, low = vis[u];
    } else if (color[v]==1) // u in a circle
        d[u] = vis[u]-vis[e[u]]+1, low = vis[v];
    else                    // u reaches a node from previous dfs
        d[u] = d[v]+1, low = vis[u];
    
    color[u] = 2;
    return low;
}

int main() {
    scanf("%d", &n);
    REP(i, 1, n) scanf("%d", &e[i]);

    REP(i, 1, n) {
        if (!color[i]) dfs(i);
        printf("%d\n", d[i]);
    }

    return 0;
}