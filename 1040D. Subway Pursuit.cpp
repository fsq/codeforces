#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    srand(time(NULL));
    ll n, k;
    cin >> n >> k;
    string ans;
    for (ll l=1, r=n; ;) {
        while (l+4*k<r) {
            ll mid = l + (r-l)/2;
            cout << l << ' ' << mid << endl;
            cout.flush();
            cin >> ans;
            if (ans=="Yes") {
                r = min<ll>(mid + k, n);
                l = max<ll>(1, l - k);
            } else if (ans=="No") {
                if (k==0 && r==l+1)
                    ++l;
                else 
                    l = max<ll>(1, mid+1 - k);
                r = min<ll>(r+k, n);
            } else
                return 0;
        }
        ll guess = l + rand()%(r-l+1);
        cout << guess << ' ' << guess << endl;
        cout.flush();    
        cin >> ans;
        if (ans=="Yes" || ans=="Bad") return 0;
        l = max<ll>(1, l-k);
        r = min<ll>(n, r+k);
    }
    return 0;
}