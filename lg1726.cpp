#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
vector<int> e[5007], et[5007];

void dfs(int x, vector<int> e[], bool vis[], vector<int>& a) {
    vis[x] = true;
    for (auto v : e[x])
        if (!vis[v])
            dfs(v, e, vis, a);
    a.push_back(x);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int a,b,t,i=1; i<=m; ++i) {
        scanf("%d %d %d", &a, &b, &t);
        if (t==1) 
            e[a].push_back(b),
            et[b].push_back(a);
        else {
            e[a].push_back(b), e[b].push_back(a);
            et[a].push_back(b), et[b].push_back(a);
        }
    }

    vector<int> ord;
    bool vis[n+1];
    memset(vis, false, sizeof(vis));
    for (int i=1; i<=n; ++i)
        if (!vis[i]) 
            dfs(i, e, vis, ord);

    memset(vis, false, sizeof(vis));
    vector<int> ans;
    for (int i=ord.size()-1; i>=0; --i)
        if (!vis[ord[i]]) {
            vector<int> cc;
            dfs(ord[i], et, vis, cc);
            sort(cc.begin(), cc.end());
            if (cc.size()>ans.size() || (cc.size()==ans.size() && cc<ans)) 
                ans = move(cc);
        }
    printf("%d\n", (int)ans.size());
    for (auto x : ans) printf("%d ", x);

    return 0;
}