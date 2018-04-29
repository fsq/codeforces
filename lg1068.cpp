#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> a(n);
    for (int i=0; i<n; ++i) cin >> a[i].second >> a[i].first;
    sort(a.begin(), a.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.first>b.first || a.first==b.first && a.second<b.second; });

    int rk = floor(m*1.5);
    int sc = a[rk-1].first;

    vector<pair<int,int>> ans;
    for (int i=0; i<n && a[i].first>=sc; ++i) 
        ans.push_back({a[i].second, a[i].first});
    
    printf("%d %d\n", sc, ans.size());
    for (auto& p : ans)
        printf("%d %d\n", p.first, p.second);

    return 0;
}