#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>
#include <bitset>

using namespace std;

int l, r, n;

vector<unordered_map<int,int>> freq(13);

int main() {
    ios::sync_with_stdio(false);
    char c;
    cin >> l >> r >> n;


    for (int now=0, i=1; cin>>c; ++i) {
        now = now << 1 | (c-'0');
        for (int len=l; len<=i && len<=r; ++len) 
            ++freq[len][now & ((1<<len)-1)];
    }

    map<int, set<pair<int,int>>> map;

    for (int i=l; i<=r; ++i)
        for (auto& kv : freq[i])
            map[kv.second].insert({i, kv.first});

    int cnt = 0;
    for (auto it=map.rbegin(); it!=map.rend() && cnt<n; ++it,++cnt) {
        cout << it->first <<'\n';
        int row = 0;
        for (auto& pr : it->second) {
            cout << bitset<12>(pr.second).to_string().substr(12-pr.first)<< ' ';
            if (++row==6) {
                cout << '\n';
                row = 0;
            }
        }
        if (row) cout << '\n';
    }
    return 0;
}