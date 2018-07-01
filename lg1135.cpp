#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool vis[300];
int  d[300], a[300];

int main() {
    ios::sync_with_stdio(false);

    int n, s, t;
    cin >> n >> s >> t;
    
    if (s==t) {
        cout << 0 << endl;
        return 0;
    }
    for (int i=1; i<=n; ++i) cin >> a[i];

    queue<int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto y : {x-a[x], x+a[x]})
            if (y>=1 && y<=n && !vis[y]) {
                vis[y] = true;
                d[y] = d[x] + 1;
                if (y==t) {
                    cout << d[y] << endl;
                    return 0;
                }
                q.push(y);
            }
    }

    cout << -1 << endl;


    return 0;
}