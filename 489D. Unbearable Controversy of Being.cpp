#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void dfs(int node, const vector<vector<int>>&edges, unordered_map<int,int>& count, int depth) {
    if (depth==2) 
        ++count[node];
    else
        for (auto nxt : edges[node])
            dfs(nxt, edges, count, depth+1);
}

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(n+1, vector<int>{});

    for (int x,y,t=m; t>0; --t) {
        cin >> x >> y;
        edges[x].push_back(y);        
    }

    unordered_map<int, int> count;
    long long ans = 0;

    for (int i=1; i<=n ;++i) {
        count.clear();
        // get all depth 2 neighbors
        dfs(i, edges, count, 0);
        for (auto& kv : count) 
            if (kv.first!=i)
                ans += (long long) kv.second * (kv.second-1) / 2;
        
    }
    cout << ans << endl;
    return 0;
}