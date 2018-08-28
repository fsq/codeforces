#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

int f[2000007];

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> k >> n;
    vector<int> a(n);
    int s = 0;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        s = max(s, a[i]*k+1);
    }

    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int i=0; i<n; ++i)
        for (int j=a[i]; j<=s; ++j)
            if (f[j-a[i]]!=0x3f3f3f3f)
                f[j] = min(f[j], f[j-a[i]]+1);
    
    for (int i=1; i<=s; ++i)
        if (f[i]>k) {
            cout << i-1 << endl;
            break;
        }
    return 0;
}