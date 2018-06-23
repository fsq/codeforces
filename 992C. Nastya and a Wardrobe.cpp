#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long m = 1e9 + 7;

long long pow(long long d) {
    if (d==0) return 1;
    if (d==1) return 2;
    long long a = pow(d>>1);
    if (d & 1) return ((a * a % m) << 1) % m;
        else   return (a * a) % m;
}

int main() {
    long long x, d;

    cin >> x >> d;
    if (x==0) {
        cout << 0 << endl;
        return 0;
    }
    x %= m;
    long long s = pow(d);

    long long ret = ((s<<1) % m) * x %m - s + 1;
    if (ret<0) ret += m;
    cout << ret << endl;

    return 0;
}