#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    int s = accumulate(a.begin(), a.end(), 0);

    if (n>1)
        for (int i=0; i<n; ++i)
            if (a[i]!=s-a[i]) {
                cout << 1 << '\n' << i+1 << endl;
                return 0;
            }

    cout << -1 << endl;
        
    
    return 0;
}