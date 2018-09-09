#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> x(n);
    for (int i=0; i<n; ++i) cin >> x[i];

    int ans = 0;
    for (int l=0, r=n-1; l<=r; ++l, --r) 
        if (x[l]!=2 && x[r]!=2) {
            if (x[l]!=x[r]) {
                ans = -1;
                break;
            }
        } else if (x[l]!=2 || x[r]!=2) {
            ans += min(x[l],x[r])==0 ? a : b;
        } else 
            ans += (l==r ? 1 : 2) * min(a, b);

    cout << ans << endl;
    return 0;    
}
