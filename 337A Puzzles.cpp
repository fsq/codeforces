#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a;
    int crnt;
    for (int t=0; t<m; ++t) {
        cin >> crnt;
        a.push_back(crnt);
    }

    sort(a.begin(), a.end());

    int ans = INT_MAX;
    for (int i=0; i+n<=a.size(); ++i) 
        ans = min(ans, a[i+n-1]-a[i]);
    cout << ans << endl;
    return 0;
}