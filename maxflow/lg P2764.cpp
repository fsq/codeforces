#include <cstdio>
#include <vector>
#include <list>
#define REP(i,a,b) for (int i=(a);i<=(b);++i)
#define cf(x,y) (c[x][y]-f[x][y]+f[y][x])

using namespace std;

typedef vector<int>::iterator VIT;

class Node {
public:
    int h, e;
    vector<int> N;
    int ptr;
    int id;
    Node() {
        id = h = e = 0;
        ptr = 0;
    }
};

const int MAXN = 500;
vector<Node> V;
int f[MAXN][MAXN], c[MAXN][MAXN];
int n, m;

void link(int x, int y) {
    c[x][y] = 1;
    V[x].N.push_back(y);
    V[y].N.push_back(x);
}

void init() {
    REP(i, 1, n) link(0, i), link(n+i, 2*n+1);
    V[0].h = n;
    for (int i=0; i<V[0].N.size(); ++i) {
        f[0][i] = 1;
        ++V[i].e;
    }
}

void relabel(int ui) {
    Node& u = V[ui];
    int h = 2*n;
    for (int i=0; i<u.N.size(); ++i)
        if (cf(ui, u.N[i])>0)
            h = min(h, V[u.N[i]].h+1);
    u.h = h;
}

void push(int u, int v) {
    int delta = min(V[u].e, cf(u, v));
    if (f[v][u]>0)
        f[v][u] -= delta;
    else 
        f[u][v] += delta;
    // if (c[u][v]>0)
    //     f[u][v] += delta;
    // else
    //     f[v][u] -= delta;
    V[u].e -= delta;
    V[v].e += delta;
}

void discharge(int ui) {
    Node& u = V[ui];
    while (u.e>0) {
        int vit = u.ptr;
        if (vit==u.N.size()) {
            relabel(ui);
            u.ptr = 0;
        } else {
            int v = u.N[vit];
            if (cf(ui, v)>0 && u.h==V[v].h+1) 
                push(ui, v);
            else 
                ++u.ptr;
        }
    }
}

int main() {
    scanf("%d %d\n", &n, &m);

    V = vector<Node>(2*n+2);    
    for (int x,y,i=0; i<m; ++i) {
        scanf("%d %d", &x, &y);
        link(x, n+y);
    }

    init();

    list<int> ls;
    REP(i, 1, n<<1) ls.push_back(i);
    list<int>::iterator it = ls.begin();
    while (it!=ls.end()) {
        Node& u = V[*it];
        int old_h = u.h;
        discharge(*it);
        if (u.h > old_h) 
            ls.splice(ls.begin(), ls, it);
        ++it;
    }

    int maxflow = 0;
    REP(i, n+1, 2*n) maxflow += f[i][2*n+1];

    vector<int> nxt(n+1);
    vector<int> rt(n+1, 1);
    REP(i, 1, n) 
        for (int j=0; j<V[i].N.size(); ++j) 
            if (f[i][V[i].N[j]]==1) {
                nxt[i] = V[i].N[j] - n;
                rt[V[i].N[j]-n] = 0;
                break;
            }
    REP(i, 1, n)
        if (rt[i]) {
            int j = i;
            do {
                printf("%d ", j);
                j = nxt[j];
            } while (j); 
            printf("\n");
        }

    printf("%d\n", n-maxflow);


    return 0;
}