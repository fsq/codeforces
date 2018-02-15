#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> ind(n+1, 0);
    vector<vector<bool>> a(n+1, vector<bool>(n+1, false));
    for (int i=0,x,y; i<m; ++i) {
        cin >> x >> y;
        --x, --y;
        a[x][y] = true;
        a[y][x] = true;
        ++ind[x], ++ind[y];
    }

    int popped = 0;
    int groups = 0;
    while (popped<n) {
        vector<int> nxt;
        for (int i=0; i<n; ++i)
            if (ind[i]==1)
                nxt.push_back(i);
        if (nxt.empty()) break;

        for (auto x : nxt)
            for (int y=0; y<n; ++y)
                if (a[x][y]) {
                    a[x][y] = a[y][x] = false;
                    --ind[x], --ind[y];
                }
        ++groups;
    }

    cout << groups << endl;

    return 0;
}