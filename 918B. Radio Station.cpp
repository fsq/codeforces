#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    unordered_map<string, string> map;
    string name, ip;
    for (int i=0; i<n; ++i) {
        cin >> name >> ip;
        map[ip+';'] = name;
    }
    string cmd;
    while (m--) {
        cin >> cmd >> ip;
        cout << cmd << ' ' << ip << " #" << map[ip] << '\n';
    }

    return 0;
}