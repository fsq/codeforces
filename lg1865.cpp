#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, m, l, r;

    cin >> n >> m;

    vector<int> p, vis(m+1);
    for (int i=2; i<=m; ++i) {
        if (!vis[i]) p.push_back(i);
        for (int j=0; j<p.size() && p[j]*i<=m; ++j) {
            vis[p[j]*i] = true;
            if (! (i%p[j])) break;
        }
    }

    while (n--) {
        cin >> l >> r;
        if (l<1 || l>m || r<1 || r>m) 
            cout << "Crossing the line\n";
        else {
            auto lf = lower_bound(p.begin(), p.end(), l) - p.begin();
            auto rt = upper_bound(p.begin(), p.end(), r) - p.begin();
            cout << (rt-lf) << '\n';
        } 
    }

    return 0;
}