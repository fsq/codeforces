#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#define cind(x) scanf("%d", &x)

using namespace std;

int n, m;
const int MAXN = 1e5 + 7;


vector<int> find_prime(int n) {
    bool vis[n+1];
    memset(vis, true, sizeof(vis));
    vector<int> ans;

    for (int i=2; i<=n; ++i) {
        if (vis[i]) 
            ans.push_back(i);
        for (int j=0; j<ans.size() && (long long)ans[j]*i<=n; ++j) {
            vis[ans[j]*i] = false;
            if (i%ans[j]==0) break;
        }
        
    }
    return ans;
}

vector<pair<int,int>> e;

int main() {
    cind(n), cind(m);

    vector<int> p = find_prime(2*n);
    // for (auto x : p) printf("%d\n", x);

    for (int i=1; i+1<n; ++i) 
        e.push_back({i+1, 1});
    
    int last = *lower_bound(p.begin(), p.end(), n-1);
    // printf("%d\n", last);
    e.push_back({n, last-n+2});

    printf("%d %d\n", last, last);

    for (int i=0; i<e.size(); ++i) 
        printf("%d %d %d\n", i+1, e[i].first, e[i].second);

    int from = 1, to = 3;

    for (int i=n; i<=m; ++i) {
        printf("%d %d %d\n", from, to, 1000000000);
        ++to;
        if (to>n) {
            ++from;
            to = from + 2;
        }
    }



    return 0;
}