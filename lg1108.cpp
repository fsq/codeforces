#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
 
    vector<vector<pair<int,int>>> a;
    int cnt = 0;
    for (int x,_i=0; _i<n; ++_i) {
        cin >> x;
        int i = lower_bound(a.begin(), a.end(), x, [](const vector<pair<int,int>>& a, int b) {
            return a.back().first > b;
        }) - a.begin();

        int cnt, j;
        if (i==0) 
            cnt = 1;
        else {
            j = upper_bound(a[i-1].begin(), a[i-1].end(), pair<int,int>{x, INT_MAX}) - a[i-1].begin();
            cnt = a[i-1].back().second - (j==0 ? 0 : a[i-1][j-1].second);
        }
        if (i==a.size())
            a.push_back({{x, cnt}});
        else {
            if (a[i].back().first==x)
                a[i].back().second = a[i].size()>1 ? a[i][a[i].size()-2].second + cnt : cnt;
            else
                a[i].push_back({x, a[i].back().second + cnt});
        }

    }
    cout << a.size() << ' ' << a.back().back().second << endl;
    return 0;
}