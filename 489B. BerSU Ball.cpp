#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, t;
    vector<int> a, b;

    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> t;
        a.push_back(t);
    }

    cin >> m;
    for (int i=0; i<m; ++i) {
        cin >> t;
        b.push_back(t);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i=0, j=0, ans = 0;
    while (i<a.size() && j<b.size()) 
        if (abs(a[i]-b[j])<=1) {
            ++ans;
            ++i; 
            ++j;
        } else if (a[i]<b[j])
            ++i;
        else 
            ++j;

    cout << ans << endl;
    return 0;
}