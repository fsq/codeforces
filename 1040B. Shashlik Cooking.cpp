#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int res = n % (2*k+1);
    vector<int> ans;
    if (res==0) {
        for (int i=k+1; i<=n; i+=2*k+1) ans.push_back(i);
    } else if (res>=k+1) {
        for (int i=res-k; i<=n; i+=2*k+1) ans.push_back(i);
    } else {
        ans.push_back(n);
        res = res + 2*k + 1 - k - 1;
        for (int i=res-k; i<n-k; i+=2*k+1) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << ' '; cout << endl;
    return 0;
}