#include <vector>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, pre = 0, x;
    long long ans = 0;
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> x;
        if (x>=pre)
            ans += x - pre;

        pre = x;
    }
    cout << ans << endl;
    return 0;
}