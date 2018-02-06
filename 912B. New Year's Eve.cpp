#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    if (k==1)
        cout << n << endl;
    else {
        long long sum = 0, accm = 1;
        while (n) {
            sum += accm;
            n >>= 1;
            accm <<= 1;
        }
        cout << sum << endl;
    }
    return 0;
}