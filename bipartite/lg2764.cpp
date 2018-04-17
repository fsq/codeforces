#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
const int MAXN = 401;
const int INF = 0x3f3f3f3f;
vector<int> e[MAXN];
int M[MAXN], d[MAXN];

bool bfs() {
    queue<int> q;
    for (int i=1; i<=n; ++i)
        if (M[i])
            d[i] = INF;
        else 
            d[i] = 0, q.push(i);
    d[0] = INF;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (d[u]<d[0])
            for (auto v : e[u])
                if (d[M[v]]==INF) {
                    d[M[v]] = d[u] + 1;
                    q.push(M[v]);
                }
    }
    return d[0] != INF;
}

bool dfs(int u) {
    if (!u) return true;
    int dt = d[u];
    d[u] = INF;
    for (auto v : e[u])
        if (d[M[v]]==dt+1 && dfs(M[v])) {
            M[v] = u, M[u] = v;
            return true;
        }
    return false;
}

void print(int u) {
    printf("%d ", u);
    if (M[u]) print(M[u]-n);
}


int main() {
    scanf("%d %d", &n, &m);
    for (int u,v,i=0; i<m; ++i) {
        scanf("%d %d", &u, &v);
        v += n;
        e[u].push_back(v);
    }

    int matching = 0;
    while (bfs()) 
        for (int i=1; i<=n; ++i)
            if (!M[i] && dfs(i)) ++matching;

    for (int i=1; i<=n; ++i)
        if (!M[i+n] && M[i])
            print(i), printf("\n");
        else if (!M[i+n] && !M[i])
            printf("%d\n", i);

    printf("%d\n", n-matching);

    return 0;
}