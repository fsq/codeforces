#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#define REP(i,a,b) for (int i=(a); i<=(b); ++i)

using namespace std;

int n, m, r, c;
int a[17][17];
int d[17][17];
int b[17];
int f[17][17][17];

int ans = INT_MAX;

int dp() {
    memset(f, 0x3f, sizeof(f));
    f[0][0][0] = 0;
    REP(i, 1, m) {
        f[i][0][0] = 0;
        REP(j, 1, i-1) f[i][1][j] = f[i-1][1][j];
        f[i][1][i] = b[i];
        REP(j, 2, min(i, c)) {
            REP(k, j, i-1) f[i][j][k] = f[i-1][j][k];
            REP(k, j-1, i-1) f[i][j][i] = min(f[i][j][i], f[i-1][j-1][k]+d[k][i]+b[i]);
        }
    }
    int ans = INT_MAX;
    REP(i, c, m) ans = min(ans, f[m][c][i]);
    return ans;
}

void gen_comb(int pre, int remain, int a[][17], vector<int>& s) {
    if (!remain) {
        memset(d, 0, sizeof(d));
        memset(b, 0, sizeof(b));
        REP(i, 0, r-2) REP(j, 1, m) b[j] += abs(a[s[i]][j]-a[s[i+1]][j]);
        for (auto x : s) 
            REP(j, 1, m) REP(i, 1, j-1)
                d[i][j] += abs(a[x][i]-a[x][j]);
        
        ans = min(ans, dp());
    } else 
        for (int i=pre+1; i<=n; ++i) {
            s.push_back(i);
            gen_comb(i, remain-1, a, s);
            s.pop_back();
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> r >> c;
    REP(i, 1, n) REP(j, 1, m) cin >> a[i][j];

    vector<int> s;
    gen_comb(0, r, a, s);

    cout << ans << endl;

    return 0;
}