#include <cstdio>
#include <vector>
#include <list>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define cf(u, v) (c[u][v]-f[u][v]+f[v][u])
using namespace std;

const int MAXN = 301;
int f[MAXN][MAXN], c[MAXN][MAXN];
int n;

class Node {
public:
    vector<int> N;
    int h,e,p;
    Node() {h=e=p=0;}
} V[MAXN];

void link(int x, int y, int d) {
    c[x][y] = d;
    V[x].N.push_back(y);
    V[y].N.push_back(x);
}

void push(int u, int v) {
    int delta = min(V[u].e, cf(u, v));
    if (f[v][u]>0)
        f[v][u] -= delta;
    else
        f[u][v] += delta;
    V[u].e -= delta;
    V[v].e += delta;
}

void relabel(int u) {
    int h = 2*n;
    for (int i=0; i<V[u].N.size(); ++i)
        if (cf(u, V[u].N[i])>0)
            h = min(h, V[V[u].N[i]].h+1);
    V[u].h = h;
}

void init() {
    V[1].h = n;
    for (int i=0; i<V[1].N.size(); ++i) {
        int v = V[1].N[i];
        f[1][v] = c[1][v];
        V[v].e += f[1][v];
    }
}

void discharge(int u) {
    Node& n = V[u];
    while (n.e) 
        if (n.p==n.N.size()) {
            relabel(u);
            n.p = 0;
        } else {
            int v = n.N[n.p];
            if (cf(u,v)>0 && n.h==V[v].h+1)
                push(u, v);
            else
                ++n.p;
        }
}

int relabel_to_front() {
    list<int> ls;
    REP(i, 2, n-1) ls.push_front(i);

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
    REP(i, 1, n-1) maxflow += f[i][n];
    return maxflow;
}



int main() {
    int m;
    while (scanf("%d %d", &m, &n)!=EOF) {
        memset(V, 0, sizeof(V));
        memset(f, 0, sizeof(f));
        memset(c, 0, sizeof(c));
        REP(i, 1, m) {
            int x, y, d;
            scanf("%d %d %d", &x, &y, &d);
            link(x, y, d);
        }

        init();
        printf("%d\n", relabel_to_front());
    }
    return 0;
}