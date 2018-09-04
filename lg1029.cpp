#include <iostream>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b) {
    return b==0 ? a : gcd(b, a%b);
}

int main() {
    long long x, y;
    cin >> x >> y;
    y *= x;
    int ans = 0;
    for (long long p=1; p<=sqrt(y); ++p) 
        if (y%p==0) {
            long long q = y / p;
            if (gcd(p, q)==x)
                ans += p==q ? 1 : 2;
        }
    cout << ans << endl;
    
    return 0;
}