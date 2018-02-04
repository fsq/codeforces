#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string s;   
    cin >> s;
    int n = s.size();
    int ans = 0;
    
    vector<vector<bool>> f(n, vector<bool>(n, false)), g=f;
    for (int l=0; l<n; ++l) {
        int sum = 0;
        int cnt = 0;
        bool valid = true;
        for (int r=l; r<n; ++r) {
            if (s[r]=='?') ++cnt;
            else sum += s[r]=='(' ? 1 : -1;
            if (sum+cnt<0)
                valid = false;
            f[l][r] = valid;
        }
    }

    for (int r=n-1; r>=0; --r) {
        int sum = 0;
        int cnt = 0;
        bool valid = true;
        for (int l=r; l>=0; --l) {
            if (s[l]=='?') ++cnt;
            else sum += s[l]==')' ? 1 : -1;
            if (sum+cnt<0) 
                valid = false;
            g[l][r] = valid;
        }
    }
    for (int l=0; l<n; ++l)
        for (int r=l; r<n; ++r)
            if (f[l][r] && g[l][r] && !((r-l+1)%2))
                ++ans;

    cout << ans << endl;
    
    return 0;
}