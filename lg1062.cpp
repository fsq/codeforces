#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int k, n;
    ll ans = 0;
    cin >> k >> n;
    for (ll s=1; n; n>>=1, s*=k) 
        if (n & 1)
            ans += s;
    cout << ans << endl;
    return 0;
}