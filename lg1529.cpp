#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int d[71][71];
int n = 52;

int trans(char c) {
    return isupper(c) ? c-'A'+27 : c-'a'+1;
}

int main() {
    memset(d, 0x3f, sizeof(d));

    int m;
    cin >> m;
    char a, b;
    int len;
    for (int i=1; i<=n; ++i) d[i][i] = 0;
    for (int i=0; i<m; ++i) {
        cin >> a >> b >> len;
        int x = trans(a), y = trans(b);
        d[y][x] = d[x][y] = min(d[x][y], len);
    }

    vector<int> vis(n+1);
    for (int t=1; t<n; ++t) {
        int mind=INT_MAX, id;
        for (int i=1; i<=n; ++i)
            if (!vis[i] && d[n][i]<mind) {
                mind = d[n][i];
                id = i;
            }
        vis[id] = true;
        for (int j=1; j<=n; ++j)
            if (!vis[j] && d[n][j]>d[n][id]+d[id][j]) 
                d[n][j] = d[n][id] + d[id][j];
    }

    int ans = INT_MAX;
    char id;
    for (char c='A'; c<'Z'; ++c)
        if (d[n][trans(c)] < ans) {
            ans = d[n][trans(c)];
            id = c;
        }
    cout << id << ' ' << ans << endl;
    return 0;
}