#include <vector>
#include <iostream>

using namespace std;

vector<long long> a;
vector<vector<pair<int,long long>>> edges;
vector<bool> vis;
int ans;

int count(int node) {
    vis[node] = true;
    int ret = 1;
    for (auto& edge : edges[node])
        if (!vis[edge.first])
            ret += count(edge.first);
    return ret;
}

void dfs(int node, long long sum) {
    vis[node] = true;
    if (node!=1 && sum>a[node]) 
        ans += count(node);
    else 
        for (auto& edge : edges[node])
            if (!vis[edge.first])
                dfs(edge.first, max(edge.second, sum+edge.second));
}

int main() {

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    a = {0};
    for (long long x,i=0; i<n; ++i) {
        cin >> x;
        a.push_back(x);
    }

    edges = vector<vector<pair<int,long long>>>(n+1, vector<pair<int,long long>>{});

    for (long long i=1,y,c; i<n; ++i) {
        cin >> y >> c;
        edges[i+1].push_back({y, c});
        edges[y].push_back({i+1, c});
    }
    vis = vector<bool>(n+2, false);
    dfs(1, 0);

    cout << ans << endl;

    return 0;
}