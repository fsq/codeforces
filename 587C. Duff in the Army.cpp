#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

#define cind(x) scanf("%d", &x)
#define MAXN 100007

using namespace std;

int n, m, q;
int root;

vector<int> live[MAXN];

class Node {
public:
    int h;
    Node() {}
} t[MAXN];

int f[MAXN][30];
vector<int> cand[MAXN][30];

vector<int> get_min(const vector<int>& a, const vector<int>& b, int cnt) {
    vector<int> ans;
    int i=0, j=0;
    while (ans.size()<min<int>(a.size()+b.size(), cnt)) 
        if (i<a.size() && (j==b.size() || a[i]<b[j]))
            ans.push_back(a[i++]);
        else
            ans.push_back(b[j++]);
    return ans;
}

void build(int fa, int node, vector<vector<int>>& te, int h) {
    f[node][0] = fa;
    cand[node][0] = live[node];
    t[node].h = h;

    for (int i=1; (1<<i)<=h; ++i) {
        int j = f[node][i-1];
        f[node][i] = f[j][i-1];
        cand[node][i] = get_min(cand[node][i-1], cand[j][i-1], 10);
    }

    for (auto nxt : te[node])
        if (nxt != fa) 
            build(node, nxt, te, h+1);
}

void init() {
    vector<vector<int>> te(n+1, vector<int>{});
    for (int x,y,i=0; i+1<n; ++i) {
        cind(x), cind(y);
        te[x].push_back(y);
        te[y].push_back(x);
    }

    for (int c,i=1; i<=m; ++i) {
        cind(c);
        live[c].push_back(i);
    }

    for (int i=1; i<=n; ++i) {
        sort(live[i].begin(), live[i].end());
        live[i].resize(min<int>(live[i].size(), 10));
    }

    root = floor(n/3) + 1;
    build(0, root, te, 0);
}

int main() {
    cind(n), cind(m), cind(q);

    init();

    for (int u,v,a,u0,v0,i=0; i<q; ++i) {
        cind(v), cind(u), cind(a);
        vector<int> ans;

        if (t[u].h < t[v].h) swap(u, v);
        v0 = v, u0 = u;

        while (t[v].h != t[u].h) {
            int pow = log2(t[u].h - t[v].h);
            ans = get_min(ans, cand[u][pow], a);
            u = f[u][pow];
        }

        if (u!=v) {
            for (int p=log2(t[v].h); p>=0; --p) 
                if (f[v][p] != f[u][p]) {
                    ans = get_min(ans, cand[v][p], a);
                    ans = get_min(ans, cand[u][p], a);

                    v = f[v][p];
                    u = f[u][p];
                }
            ans = get_min(ans, live[v], a);
            ans = get_min(ans, live[u], a);
            ans = get_min(ans, live[f[u][0]], a);
        } else 
            ans = get_min(ans, live[u], a);

        printf("%lu ", ans.size());
        for (auto x : ans) printf("%d ", x);
        printf("\n");
    }

    return 0;
}