#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, d, x, y, ans=2;
    cin >> n >> d >> x;
    d <<= 1;
    for (int i=1; i<n; ++i) {
        cin >> y;
        if (y - x > d) ans += 2;
            else if (y - x == d) ++ans;
        x = y;
    }
    cout << ans << endl;

    return 0;
}