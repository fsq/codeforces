#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// similar to topological sort
// but on undirected graph

int main() {

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> deg;
    vector<int> s;
    queue<int> q;
    vector<vector<int>> edge;

    for (int d,xr,i=0; i<n; ++i) {
        cin >> d >> xr;
        deg.push_back(d);
        s.push_back(xr);
        edge.push_back({});
        if (d==1)
            q.push(i);
    }

    int count_edge = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (deg[now]==0) continue;

        --deg[now];
        int nxt = s[now];
        edge[now].push_back(nxt);
        s[nxt] ^= now;
        ++count_edge;

        if (--deg[nxt]==1)
            q.push(nxt);
    }
    cout << count_edge << '\n';
    for (int i=0; i<n; ++i)
        for (auto nxt : edge[i])
            cout << i << ' ' << nxt << '\n';

    return 0;
}