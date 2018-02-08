#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a;
    for (int x,i=0; i<n; ++i) {
        cin >> x;
        a.push_back(x);
    }
    long long f = INT_MIN, g = f;
    long long ans = INT_MIN;
    for (auto x : a) 
        if (x & 1) {
            long long nxtf = max(f, max<long long>(x, g+x));
            g = max(g, f + x);
            f = nxtf;
            ans = max(ans, f);
        } else {
            f = max(f, f + x);
            g = max(g, max<long long>(x, g+x));
            ans = max(ans, f);
        }
    cout << ans << endl;

    return 0;
}