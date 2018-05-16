#include <vector>
#include <cstdio>
#include <numeric>
#include <cstring>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define PER(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

const int N = 107;
int n;
vector<int> e[N], et[N], fa, od, id;
bool vis[N];

void dfs(int x, vector<int> e[], vector<int>& a, bool vis[]) {
    vis[x] = true;
    for (int y : e[x])
        if (!vis[y])
            dfs(y, e, a, vis);
    a.push_back(x);
}

int find(int x) {
    return fa[x]==x ? x : fa[x]=find(fa[x]);
}

int main() {
    scanf("%d", &n);
    for (int j,i=1; i<=n; ++i) {
        while (true) {
            scanf("%d", &j);
            if (j==0) break;
            e[i].push_back(j);
            et[j].push_back(i);
        }
    }

    vector<int> ord;
    REP(i, 1, n)
        if (!vis[i])
            dfs(i, e, ord, vis);

    memset(vis, false, sizeof(vis));
    fa.resize(n+1);
    iota(fa.begin(), fa.end(), 0);
    PER(i, n-1, 0)
        if (!vis[ord[i]]) {
            vector<int> cc;
            dfs(ord[i], et, cc, vis);
            for (auto x : cc) fa[x] = ord[i];
        }

    od.resize(n+1), id.resize(n+1);
    REP(u, 1, n)
        for (int v : e[u]) 
            if (find(u)!=find(v))
                ++od[fa[u]], ++id[fa[v]];

    int ans1=0, ans2=0, cnt=0;
    REP(i, 1, n)
        if (find(i)==i) {
            ++cnt;
            if (!id[i]) ++ans1;
            if (!od[i]) ++ans2;
        }

    printf("%d\n%d\n", ans1, cnt!=1 ? max(ans1, ans2) : 0);


    return 0;
}