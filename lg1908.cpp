#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

int n;
vector<int> a;

int lowbit(int x) { return x & -x; }

int sum(vector<int>& s, int i) {
    int ret = 0;
    for (++i; i; i-=lowbit(i)) ret += s[i];
    return ret;
}

void add(vector<int>& s, int i) {
    for (++i; i<s.size(); i+=lowbit(i)) ++s[i];
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    a.resize(n);
    for (int i=0; i<n; ++i) cin >> a[i];

    auto id = a;
    sort(id.begin(), id.end());
    id.resize(unique(id.begin(), id.end()) - id.begin());

    vector<int> s(id.size()+1), ans;

    int cnt = 0;
    for (auto x : a) {
        int i = lower_bound(id.begin(), id.end(), x) - id.begin();
        ans.push_back(cnt - sum(s, i-1));
        add(s, i);
        ++cnt;
    }

    // for (auto x : ans) cout << x << ' ';
    // cout << endl;
    cout << accumulate(ans.begin(), ans.end(), 0) << endl;
    return 0;
}