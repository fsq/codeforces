#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];

    int l=0, r=n-1;
    while (a[l]) l = (l+1) % n;
    while (a[r]) r = (r-1+n) % n;
    if ( (l&1) || ((n-r-1)&1) )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}