#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long ans = 0;
    for (int i=1; i<=n; ++i)
        ans += n / i;
    cout << ans << endl;
    return 0;
}