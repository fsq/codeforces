#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> cnt(3);
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        --a[i];
        ++cnt[a[i]];
    }

    int ans = 0;
    for (int i=0; i<n; ++i)
        if (i<cnt[0]) {
            if (a[i]!=0) {
                bool found = false;
                ++ans;        
                if (a[i]==1)
                    for (int j=cnt[0]; j<cnt[1]+cnt[0]; ++j)
                        if (a[j]==0) {
                            swap(a[i], a[j]);
                            found = true; break;
                        }
                if (!found)
                    for (int j=cnt[1]+cnt[0]; j<n; ++j)
                        if (a[j]==0) {
                            swap(a[i], a[j]);
                            break;
                        }
            }
        } else if (i<cnt[1]+cnt[0]) {
            if (a[i]!=1) {
                ++ans;
                for (int j=cnt[1]+cnt[0]; j<n; ++j)
                    if (a[j]==1) {
                        swap(a[i], a[j]);
                        break;
                    }
            }
        } 
    
    cout << ans << endl;
    return 0;
}