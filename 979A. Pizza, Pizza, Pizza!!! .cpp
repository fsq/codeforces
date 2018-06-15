#include <iostream>

using namespace std;

int main() {
    long long x;
    cin >> x;
    if (x==0) 
        cout << 0 << endl;
    else {
        ++x;
        cout << ((x&1) ? x : (x>>1)) << endl;
    }
    return 0;
}