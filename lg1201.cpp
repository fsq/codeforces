#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    string s;
    unordered_map<string, int> map;
    vector<string> names;
    for (int i=0; i<n; ++i) {
        cin >> s;
        names.push_back(s);
        map[s] = 0;
    }

    for (int x,m,i=0; i<n; ++i) {
        cin >> s >> x >> m;
        if (!m) continue;
        map[s] -= x - x % m;
        for (int j=0; j<m; ++j) {
            cin >> s;
            map[s] += x / m;
        }
    }

    for (auto& name : names)
        cout << name << ' ' << map[name] << endl;

    return 0;
}