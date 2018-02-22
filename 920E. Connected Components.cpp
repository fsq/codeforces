#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

// modified BFS
// O(n)

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<unordered_set<int>> e(n+1, unordered_set<int>{});

    for (int x,y,i=0; i<m; ++i) {
        cin >> x >> y;
        e[x].insert(y);
        e[y].insert(x);
    }

    vector<int> color(n+1, 0);
    vector<int> count;
    int com_ind = 0;

    unordered_set<int> unvis;
    for (int i=1; i<=n; ++i) unvis.insert(i);

    queue<int> q;    
    while (!unvis.empty()) {
        int now = *unvis.begin();
        unvis.erase(unvis.begin());
        color[now] = com_ind;
        count.push_back(1);
        q.push(now);
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (auto it=unvis.begin(); it!=unvis.end();)
                if (e[now].find(*it)==e[now].end()) {
                    color[*it] = com_ind;
                    ++count.back();
                    q.push(*it);
                    it = unvis.erase(it);
                } else 
                    ++it;
        }
        ++com_ind;
    }
    sort(count.begin(), count.end());
    cout << count.size() << '\n';
    for (int i=0; i+1<count.size(); ++i) cout << count[i] << ' ';
    cout << count.back() << endl;
    return 0;
}