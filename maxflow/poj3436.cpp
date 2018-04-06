#include <cstdio>
#include <vector>
#include <memory>
#include <list>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define CLEAR(x) (memset(x, 0, sizeof(x)))
#define FOR(i,p) for(int i=0; i<(p); ++i)
#define SZ(x) ((int)(x).size())
#define cf(u, v) (c[u][v]-f[u][v]+f[v][u])

using namespace std;

const int MAXN = 203;
const int MAXP = 21;
const int INF = 2000000000;
int p, n, sink;
int f[MAXN][MAXN], c[MAXN][MAXN];
int spd[MAXN];
int in[MAXN][MAXP], out[MAXN][MAXP];

class Node {
public:
    vector<int> N;
    int h,e,ptr;
    Node() { h=e=ptr= 0; }
};

Node V[MAXN];

void link(int i, int j) {
    c[i][j] = spd[i];
    V[i].N.push_back(j);
    V[j].N.push_back(i);
}

void _push(int u, int v, int val) {
    f[u][v] += val;
    V[u].e -= val;
    V[v].e += val;
}

void init() {
    REP(i, 1, n) {
        link(i, n+i);
        bool canin = true, canout = true;
        FOR(j, p) {
            if (in[i][j]==1) canin = false;
            if (out[i][j]==0) canout = false;
        }
        if (canin) link(0, i);
        if (canout) link(n+i, sink);
    }
    FOR(i, SZ(V[0].N)) _push(0, V[0].N[i], c[0][V[0].N[i]]);
    V[0].h = 2*n+2;
}

void relabel(int u) {
    int h = (n+1)<<2;
    FOR(i, SZ(V[u].N))
        if (cf(u, V[u].N[i])>0)
            h = min(h, V[V[u].N[i]].h+1);
    V[u].h = h;
}

void push(int u, int v) {
    int delta = min(V[u].e, cf(u, v));
    if (f[v][u]>0)
        _push(v, u, -delta);
    else
        _push(u, v, delta);
}

void discharge(int u) {
    Node& n = V[u];
    while (n.e>0) 
        if (n.ptr==SZ(n.N)) {
            relabel(u);
            n.ptr = 0;
        } else {
            int v = n.N[n.ptr];
            if (n.h==V[v].h+1 && cf(u, v)>0) 
                push(u, v);
            else
                ++n.ptr;
        }
}

int main() {
    while (scanf("%d %d", &p, &n)!=EOF) {
        CLEAR(f), CLEAR(c), CLEAR(spd), CLEAR(in), CLEAR(out);
        CLEAR(V);
        spd[0] = INF;
        sink = 2*n+1;
        REP(i, 1, n) {
            scanf("%d", &spd[i]), spd[n+i] = spd[i];
            REP(j, 0, p-1) scanf("%d", &in[i][j]);
            REP(j, 0, p-1) scanf("%d", &out[i][j]);
        }

        REP(i, 1, n) REP(j, 1, n)
            if (i!=j) {
                bool valid = true;
                FOR(k, p)
                    if ((out[i][k] ^ in[j][k])==1) {
                        valid = false;
                        break;
                    } 
                if (valid) link(n+i, j);  
            } 

        init();
        list<int> ls;
        REP(i, 1, n<<1) ls.push_back(i);
        list<int>::iterator it = ls.begin();
        while (it!=ls.end()) {
            int u = *it;
            int oldh = V[u].h;
            discharge(u);
            if (V[u].h>oldh) 
                ls.splice(ls.begin(), ls, it);
            ++it;
        }

        int maxflow = 0;
        REP(i, 1, n) maxflow += f[n+i][sink];
        vector<pair<int,int> >  ans;
        REP(i, 1, n) REP(j, 1, n)
            if (i!=j && f[n+i][j]>0) 
                ans.push_back(pair<int,int>(i, j));
        printf("%d %d\n", maxflow, SZ(ans));
        FOR(i, SZ(ans))
            printf("%d %d %d\n", ans[i].first, ans[i].second,
                                f[n+ans[i].first][ans[i].second]);
    }
    return 0;
}