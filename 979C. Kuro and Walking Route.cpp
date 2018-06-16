#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int x, y;
long long n;
vector<int> sz;
vector<int> e[300007];
bool vis[300007];

bool dfs(int u) {
    vis[u] = sz[u] = 1;
    bool reach = false;
    for (auto v : e[u])
        if (!vis[v]) {
            if (dfs(v)) reach = true;
            sz[u] += sz[v];
        }
    return reach || u==y;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> x >> y;
    for (int u,v,i=0; i+1<n; ++i) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    sz.resize(n+1);

    vis[x] = true, sz[x] = 1;
    int z;
    for (auto v : e[x]) {
        if (dfs(v)) z = v;
        sz[x] += sz[v];
    }

    cout << n*(n-1) - (n-sz[z])*sz[y] << endl;


    return 0;
}