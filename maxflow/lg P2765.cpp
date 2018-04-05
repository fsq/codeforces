#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#include <memory>
#include <list>
using namespace std;

#define PB                  push_back
#define F                   first
#define S                   second

#define REP(i,from,to)      for(auto i=(from); i<=(to); ++i)
#define PER(i,from,to)      for(auto i=(from); i>=(to); --i)
#define REP_IF(i,from,to,assert)   for(auto i=(from); i<=(to); ++i) if (assert)

#define FOR(i,less_than)    for (auto i=0; i<(less_than); ++i)
#define FORI(i, container)  for (auto i=0; i<(container).size(); ++i)
#define FORI_IF(i, container, assert) for (auto i=0; i<(container).size(); ++i) if (assert)
#define ROFI(i, container)  for (auto i=(container).size()-1; i>=0; --i)

#define FOREACH(elem, container)  for (auto elem : (container))
#define FILL(container, value)    memset(container, value, sizeof(container))
#define ALL(container)            (container).begin(), (container).end()
#define SZ(container)             (int)((container).size())

#define BACK(set_map)       *prev((set_map).end(), 1)
#define FRONT(set_map)      *(set_map).begin()

inline void _RD(int &x) { scanf("%d", &x); }
inline void _RD(long long &x) { scanf("%lld", &x); }
inline void _RD(double &x) { scanf("%lf", &x); }
inline void _RD(long double &x) { scanf("%Lf", &x); }
inline void _RD(char &x) { scanf(" %c", &x); }
inline void RD() {}
template<class T, class... U> 
inline void RD(T &head, U &... tail) { _RD(head); RD(tail...); }

using PII = pair<int,int>;
using LL  = long long;
using VI  = vector<int>;
using VLL = vector<LL>;
using VVI = vector<VI>;
#define nid(x) ((x)<<1 | 1)
#define cf(x,y) (c[x][y]-f[x][y]+f[y][x])

class Node {
public:
    VI N;
    int h, e, ptr; 
    Node() { h=e=ptr = 0; }
};

const int MAXN = 4003;
int f[MAXN][MAXN], c[MAXN][MAXN];
Node V[MAXN];
int balls;
list<int> ls;

void link(int x, int y) {
    c[x][y] = 1;
    V[x].N.push_back(y);
    V[y].N.push_back(x);
}

void relabel(int u) {
    int h = (1+balls)<<2; // 2V = 2 * 2*(balls+1)
    FOREACH(nxt, V[u].N)
        if (cf(u, nxt)>0)
            h = min(h, V[nxt].h+1);
    V[u].h = h;
}

void push(int u, int v) {
    int d = min(V[u].e, cf(u, v));
    if (f[v][u]>0)
        f[v][u] -= d;
    else
        f[u][v] += d;
    V[u].e -= d;
    V[v].e += d;
}

void discharge(int u) {
    Node& n = V[u];
    while (n.e>0) {
        int p = n.ptr;
        if (p==n.N.size()) {
            relabel(u);
            n.ptr = 0;
        } else {
            int v = n.N[p];
            if (n.h==V[v].h+1 && cf(u, v)>0) 
                push(u, v);
            else
                ++n.ptr;
        }
    }
}

int relabel_to_front(int id) {
    // init id
    link(1, id);
    link(id+1, 2);
    REP(i, 1, balls)
        if (f[1][nid(i)]==0) {
            f[1][nid(i)] = 1;
            ++V[nid(i)].e;
        }
        
    V[1].h = (1+balls) << 1;
    ls.push_front(id);
    ls.push_back(id+1);

    auto it = ls.begin();
    while (it!=ls.end()) {
        int u = *it;
        int old_h = V[u].h;
        discharge(u);
        if (V[u].h > old_h) 
            ls.splice(ls.begin(), ls, it);
        ++it;
    }

    int maxflow = 0;
    REP(i, 1, balls) maxflow += f[(i+1)<<1][2];
    return maxflow;
}

int main() {
    int num_pillars;
    RD(num_pillars);

    int min_cover = 1;

    while (min_cover<=num_pillars) {
        ++balls;

        const int id = nid(balls); // node index
        REP(i, 1, balls-1) {
            int s = i + balls, rt = sqrt(s);
            if (rt*rt==s)  link(nid(i), id+1);
        }

        int maxflow = relabel_to_front(id);
        min_cover = balls - maxflow;
    }

    VI pted(balls+1, 0);
    --balls;

    printf("%d\n", balls);

    REP(i, 1, balls) 
        if (!pted[i]) {
            int j = nid(i);
            bool found = false;    
            do {
                printf("%d ", (j-1)>>1);
                pted[(j-1)>>1] = 1;
                found = false;
                FOREACH(nxt, V[j].N)
                    if (f[j][nxt]) {
                        j = nxt-1;
                        found = true;
                        break;
                    }
            } while (found);
            printf("\n");
        }

    return 0;
}