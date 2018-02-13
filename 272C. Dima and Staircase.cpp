#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);

    int n;
    vector<pair<int, long long>> a;

    cin >> n;
    long long t;
    for (int i=0; i<n; ++i) {
        cin >> t;
        a.push_back({i+1, t});
    }
    reverse(a.begin(), a.end());

    int m;
    long long w, h;
    cin >> m;

    while (m--) {
        cin >> w >> h;
        long long max = 0;
        while (!a.empty() && a.back().first<=w) {
            max = a.back().second;
            a.pop_back();
        }
        if (max==0) 
            max = a.back().second;
        cout << max << endl;
        max += h;
        while (!a.empty() && a.back().second<=max) 
            a.pop_back();
        a.push_back({w, max});
    }

    return 0;
}