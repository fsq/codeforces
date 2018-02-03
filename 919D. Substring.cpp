#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> edges;
vector<int> indeg;
vector<char> ch;
vector<vector<int>> f;

bool init() {
    cin >> n >> m;
    edges = vector<vector<int>>(n, vector<int>{});
    string s;
    cin  >> s;
    for (auto c : s) {
        ch.push_back(c);
        indeg.push_back(0);
        f.push_back(vector<int>(26, 0));
    }
    for (int x,y,i=0; i<m; ++i) {
        cin >> x >> y;
        if (x==y) return true;
        --x, --y;
        ++indeg[y];
        edges[x].push_back(y);
    }
    return false;
}

int main() {
    if (init()) 
        cout << -1 << endl;
    else {
        vector<int> q;
        for (int i=0; i<n; ++i)
            if (indeg[i]==0) 
                q.push_back(i);

        int l = 0, max_freq = 0;
        while (l<q.size()) {
            int now = q[l++];
            ++f[now][ch[now]-'a'];
            max_freq = max(max_freq, *max_element(f[now].begin(), f[now].end()));
            for (auto nxt : edges[now]) {
                for (int i=0; i<26; ++i)
                    f[nxt][i] = max(f[nxt][i], f[now][i]);
                if (--indeg[nxt]==0) 
                    q.push_back(nxt);
            }
        }
        if (q.size()<n) 
            cout << -1 << endl;
        else 
            cout << max_freq << endl;
    }
    return 0;
}