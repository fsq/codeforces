#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m, k;
    // cin >> n >> m >> k;
    scanf("%d %d %d\n", &n, &m, &k);
    char c;
    // vector<vector<int>> f(n, vector<int>(m, 0)), g=f;
    vector<int> f(m+1, 0), pre(m+1, 0), g(m+1, 0);

    int ans = 0;
    string line;    
    for (int i=0; i<n; ++i){
        cin >> line;
        for (int j=0; j<m; ++j) {
            if (line[j]=='.') {
                f[j] = j==0 ? 1 : f[j-1] + 1;
                g[j] = i==0 ? 1 : pre[j] + 1;
                if (f[j]>=k) ++ans;
                // beware when k==1 !!
                if (k!=1 && g[j]>=k) ++ans;
            } else 
                f[j] = g[j] = 0;
        }
        g.swap(pre);
    }
    cout << ans << endl;

    return 0;
}