#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    long long a, b, x, y, z;
    cin >> a >> b >> x >> y >> z;

    cout << max(2*x+y-a, 0ll) + max(y+3*z-b, 0ll)  << endl;

    return 0;
}