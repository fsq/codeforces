#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main() {
    string a;
    int m;
    cin >> a >> m;

    vector<vector<int>> trans(10);
    for (int x,y,i=0; i<m; ++i) {
        cin >> x >> y;
        trans[x].push_back(y);
    }

    for (int i=0; i<10; ++i) trans[i].push_back(i);

    for (auto& a : trans) {
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
    }

    vector<long long> f(10);
    for (int i=0; i<trans.size(); ++i) {
        vector<int> vis(10);
        queue<int> q;
        for (auto c : trans[i]) {
            q.push(c);
            vis[c] = 1;
            ++f[i];
        }
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (auto y : trans[x]) 
                if (!vis[y]) {
                    vis[y] = 1;
                    q.push(y);
                    ++f[i];
                }
        }
    }

    vector<long long> ans(50);
    ans[0] = 1;
    for (auto c : a) {
        long long x = f[c-'0'];
        long long carr = 0;
        for (int i=0; i+1<ans.size(); ++i) {
            ans[i] = ans[i]*x + carr;
            carr = ans[i] / 10;
            ans[i] %= 10;
        }
    }
    int i;
    for (i=ans.size()-1; !ans[i]; --i);
    while (i>=0) cout << ans[i--];
    cout << endl;
    return 0;
}