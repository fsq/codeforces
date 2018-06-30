#include <iostream>

using namespace std;

int f[101];

int main() {
    int n, k;
    cin >> n >> k;

    f[0] = 1;
    for (int i=1; i<=k; ++i) 
        for (int j=0; j<i; ++j)
            f[i] = (f[i] + f[j]) % 100003;
    for (int i=k+1; i<=n; ++i)
        f[i%(k+1)] = (2*f[(i-1+k+1) % (k+1)] - f[i%(k+1)] + 100003) % 100003;
        
    cout << f[n%(k+1)] << endl;
    return 0;
}