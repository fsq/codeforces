#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    if (a.size()&1) 
        cout << a[a.size()>>1] << endl;
    else 
        cout << a[(a.size()>>1) - 1] << endl;
    return 0;
}