#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

vector<pair<int,int>> e[103];
vector<int> comp;

void init() {
    unordered_set<int> st;
    int m;
    cin >> m;
    for (int i,j,p,t=0; t<m; ++t) {
        cin >> i >> j >> p;
        e[i].push_back({j, p});
        st.insert(i), st.insert(j);
    }

    comp = vector<int>(st.begin(), st.end());
    sort(comp.begin(), comp.end());
}

vector<int> bfs(int from) {
    vector<int> vis(103), control(103);
    vis[from] = true;
    queue<int> q;
    q.push(from);

    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (auto& edge : e[x]) {
            control[edge.first] += edge.second;
            if (control[edge.first]>=50 && !vis[edge.first]) {
                vis[edge.first] = true;
                q.push(edge.first);
            }
        }
    }
    vector<int> ans;
    for (auto x : comp) 
        if (x!=from && control[x]>=50)
            ans.push_back(x);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    init();

    for (int i=0; i<comp.size(); ++i) {
        vector<int> sub = bfs(comp[i]);
        for (auto y : sub)
            cout << comp[i] << ' ' << y << '\n';
    }



    return 0;
}