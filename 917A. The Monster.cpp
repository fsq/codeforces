// DEBUGGING
// WRONG ANSWER

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int dp(const string& s, vector<vector<int>>& f, vector<vector<int>>& g, int l, int r) {
    // printf("%d %d\n", l, r);

    if (f[l][r]!=-1) return f[l][r];

    auto& max = f[l][r];
    auto& min = g[l][r];
    max = min = 0;

    if (l>=r || s[l]==')')
        max = min = 0;
    else {
        if (s[r]!='(' && dp(s,f,g,l+1,r-1)==(r-l-1)) {
            max = min = r - l + 1;
        }
        dp(s, f,g, l, r-1);
        if (g[l][r-1]!=0) {
            int len = g[l][r-1]+dp(s,f,g,l+g[l][r-1],r);
            max = len>max ? len : max;
            min = g[l][r-1];
        } 
    }
    return max;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> f(n+1, vector<int>(n+1, -1)), g=f;
    int ans = 0;
    for (int l=0; l<n; ++l)
        for (int r=l+1; r<n; ++r)
            if  (dp(s, f, g, l, r)==r-l+1)
                ++ans;

    cout << ans << endl;

    return 0;
}