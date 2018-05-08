#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> e[10007];
int a[10007], f[10007], ind[10007];

int main() {
    int n;
    scanf("%d", &n);
    for (int u, v, i=1; i<=n; ++i) {
        scanf("%d %d", &v, &a[i]);
        
        while (scanf("%d", &u), u) {
            e[u].push_back(v);
            ++ind[v];
        }
    }

    queue<int> q;
    for (int i=1; i<=n; ++i)
        if (!ind[i])
            f[i] = a[i], q.push(i);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : e[u]) {
            f[v] = max(f[v], f[u] + a[v]);
            if (--ind[v]==0) 
                q.push(v);
        }
    }

    printf("%d\n", *max_element(f+1, f+n+1));

    return 0;
}