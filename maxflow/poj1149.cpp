#include <cstdio>
#include <vector>
#include <list>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(j, x) for(int j=0; j<x; ++j)
#define SZ(x) ((int)(x).size())
#define PB push_back
#define cf(u,v) (c[u][v]-f[u][v]+f[v][u])
using namespace std;

class Node {
public:
    int h,e,p;
    vector<int> N;
    Node() {h=e=p=0; }
};
const int MAXN = 301;
const int INF = 2000000000;
int m, n, sink;
vector<int> k[MAXN];
int a[1007], nd[MAXN], f[MAXN][MAXN], c[MAXN][MAXN];
Node V[MAXN];

void link(int u, int v, int cap) {
    c[u][v] = cap;
    V[u].N.PB(v);
    V[v].N.PB(u);
}

bool share(int u, int v) {
    int i=0, j=0;
    while (i<k[u].size() && j<k[v].size()) 
        if (k[u][i]==k[v][j])
            return true;
        else if (k[u][i]<k[v][j])
            ++i;
        else
            ++j;
    return false;
}

void build() {
    REP(i, 1, n) {
        int cap = 0;
        FOR(j, SZ(k[i])) {
            cap += a[k[i][j]];
            a[k[i][j]] = 0;
        }
        link(0, i, cap);
        link(i, sink, nd[i]);
    }
    REP(i, 1, n) 
        REP(j, i+1, n)
            if (share(i, j))
                link(i, j, INF);
}

void _push(int u, int v, int val) {
    f[u][v] += val, V[u].e -= val, V[v].e += val;
}

void init() {
    V[0].h = sink + 1;
    FOR(i, SZ(V[0].N)) _push(0, V[0].N[i], c[0][V[0].N[i]]);
}

void relabel(int u) {
    int h = (sink+1)<<1;
    FOR(i, SZ(V[u].N))
        if (cf(u, V[u].N[i])>0) 
            h = min(h, V[V[u].N[i]].h+1);
    V[u].h = h;
}

void push(int u, int v) {
    int val = min(V[u].e, cf(u, v));
    if (f[v][u]>0)
        _push(v, u, -val);
    else
        _push(u, v, val);
}

void discharge(int u) {
    Node& n = V[u];
    while (n.e>0) 
        if (n.p==SZ(n.N)) {
            relabel(u);
            n.p = 0;
        } else {
            int v = n.N[n.p];
            if (cf(u, v)>0 && n.h==V[v].h+1) 
                push(u, v);
            else
                ++n.p;
        }
}

int relabel_to_front() {
    init();
    list<int> ls;
    REP(i, 1, n) ls.push_back(i);
    list<int>::iterator it = ls.begin();
    while (it != ls.end()) {
        int u = *it, oldh = V[u].h;
        discharge(u);
        if (V[u].h > oldh)
            ls.splice(ls.begin(), ls, it);
        ++it;
    }

    int flow = 0;
    REP(i, 1, n) flow += f[i][sink];
    return flow;
}

int main() {
    scanf("%d %d", &m, &n);
    sink = n + 1;

    REP(i, 1, m) scanf("%d", &a[i]);

    REP(i, 1, n) {
        int ks, ki;
        scanf("%d", &ks);
        k[i].reserve(ks);
        REP(j, 1, ks) {
            scanf("%d", &ki);
            k[i].PB(ki);
        }
        scanf("%d", &nd[i]);
    }

    build();

    printf("%d\n", relabel_to_front());

    return 0;
}