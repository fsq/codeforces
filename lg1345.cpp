#include <vector>
#include <cstdio>
#include <algorithm>
#include <list>
#define REP(i,a,b) for(int i=(a); i<=(b); ++i)
#define PB push_back
#define cf(u, v) c[u][v]-f[u][v]+f[v][u]

using namespace std;

const int MAXN = 303;

struct Node {
    vector<int> N;
    int e, p, h;
    Node() { h=e=p=0; }
} V[MAXN];

int n, m, s, t, INF;
int f[MAXN][MAXN], c[MAXN][MAXN];

void _push(int u, int v, int c) {
    f[u][v] += c;
    V[u].e -= c;
    V[v].e += c;
}

void push(int u, int v) {
    int fl = min(V[u].e, cf(u, v));
    if (f[v][u]>0) _push(v, u, -fl);
        else     _push(u, v, fl);
}

void relabel(int u) {
    V[u].h = n << 1;
    for (auto v : V[u].N)
        if (cf(u, v)>0)
            V[u].h = min(V[u].h, V[v].h+1);
}

void discharge(int u) {
    for (auto& N=V[u]; N.e; )
        if (N.p==N.N.size()) {
            relabel(u);
            N.p = 0;
        } else {
            int v = N.N[N.p];
            if (V[v].h+1==N.h && cf(u, v)>0)
                push(u, v);
            else
                ++N.p;
        }
}

void link(int u, int v, int cap) {
    c[u][v] = cap;
    V[u].N.PB(v), V[v].N.PB(u);
}

int main() {
    scanf("%d %d %d %d", &n, &m, &s, &t);
    INF = n;
    REP(i, 1, m) {
        int u, v;
        scanf("%d %d", &u, &v);
        link(u+n, v, INF);
        link(v+n, u, INF);
    }
    REP(i, 1, n) {
        int cap = i==s || i==t ? INF : 1;
        c[i][i+n] = c[i+n][i] = cap;
        V[i].N.PB(i+n), V[i+n].N.PB(i);
    }
    t += n;
    n <<= 1;
    V[s].h = n;
    for (auto v : V[s].N) _push(s, v, c[s][v]);

    list<int> ls;
    REP(i, 1, n) if (i!=s && i!=t) ls.PB(i);

    for (auto it=ls.begin(); it!=ls.end(); ++it) {
        int u = *it, h = V[u].h;
        discharge(u);
        if (V[u].h!=h)
            ls.splice(ls.begin(), ls, it);
    }   

    printf("%d\n", V[t].e);

    return 0;
}