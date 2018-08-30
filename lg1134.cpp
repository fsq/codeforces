#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long x = 1;
    for (int i=1; i<=n; ++i) {
        x *= i;
        while (x%10==0) x /= 10;
        x %= 100000000;
    }
    cout << x%10 << endl;

    return 0;
}