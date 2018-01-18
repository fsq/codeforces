#include <iostream>

using namespace std;

int main() {
    long long n, m, a;
    cin >>n >> m >> a;
    long long x = 1 + (n-1) / a;
    long long y = 1 + (m-1) / a;
    cout << x*y << endl;
    return 0;
}