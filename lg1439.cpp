#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (int x,i=0; i<n; ++i) {
        cin >> x;
        a[x-1].first = i;
    }
    for (int x,i=0; i<n; ++i) {
        cin >> x;
        a[x-1].second = i;
    }

    sort(a.begin(), a.end());

    vector<int> s;
    for (auto& p : a) {
        auto i = lower_bound(s.begin(), s.end(), p.second) - s.begin();
        if (i==s.size())
            s.push_back(p.second);
        else 
            s[i] = p.second;
    }
    cout << s.size() << endl;



    return 0;
}