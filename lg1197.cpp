#include <vector>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>

using namespace std;

vector<int> e[400007];
vector<int> fa;
int cc;

int find(int x) { return fa[x]==x ? x : fa[x]=find(fa[x]); }

void merge(int u, int v) {
    int fu=find(u), fv=find(v);
    if (fu!=fv) {
        fa[fu] = fv;
        --cc;
    }
}

int main() {
    int n, m, k;
    
    scanf("%d %d", &n, &m);
    for (int u,v,i=0; i<m; ++i) {
        scanf("%d %d", &u, &v);
        ++u, ++v;
        e[u].push_back(v), e[v].push_back(u);
    }

    scanf("%d", &k);

    bool st[n+1];
    memset(st, true, sizeof(st));

    vector<int> del;
    for (int x,i=0; i<k; ++i) {
        scanf("%d", &x);
        ++x;
        del.push_back(x);
        st[x] = false;
    }
    
    fa.resize(n+1);
    iota(fa.begin(), fa.end(), 0);
    cc = 0;
    for (int u=1; u<=n; ++u)
        if (st[u]) {
            ++cc;
            for (auto v: e[u])
                if (st[v])
                    merge(u, v);
        }

    vector<int> ans;
    ans.push_back(cc);
    for (int i=del.size()-1; i>=0; --i) {
        ++cc;
        st[del[i]] = true;
        for (auto v : e[del[i]])
            if (st[v])
                merge(v, del[i]);
        ans.push_back(cc);
    }

    for (int i=ans.size()-1; i>=0; --i) printf("%d\n", ans[i]);
    return 0;
}