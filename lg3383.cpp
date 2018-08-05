#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> prime;
    vector<int> vis(n+1);
    vis[1] = true;
    for (int i=2; i<=n; ++i) {
        if (!vis[i]) prime.push_back(i);
        for (int j=0; j<prime.size() && prime[j]*i<=n; ++j) {
            vis[prime[j]*i] = true;
            if (!(i%prime[j])) break;
        }
    }
    for (int x,i=0; i<m; ++i) {
        cin >> x;
        cout << (vis[x]? "No" : "Yes") << endl;
    }
    return 0;
}