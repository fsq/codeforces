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
#include <climits>
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

int M[2003];
int d[1003];
VI e[2003];
int n, m;
const int INF = 0x3f3f3f3f; //1e9

bool bfs() {
    queue<int> q;

    // only consider all left nodes
    REP(i, 1, n)
        if (!M[i])  // add free U vertices to queue
            d[i] = 0, q.push(i);
        else 
            d[i] = INF;
    d[0] = INF;

    // build layers
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (d[u]<d[0]) // shorter than current shortest aug path
            FOREACH(v, e[u])
                if (d[M[v]]==INF) { // u~v->M[v], M[v] unvisited(including 0)
                    d[M[v]] = d[u] + 1;
                    q.push(M[v]);
                }
    }
    return d[0] != INF; // exist aug path
}

bool dfs(int u) {
    if (!u) return true;
    int du = d[u];
    d[u] = INF;
    FOREACH(v, e[u])
        if (d[M[v]]==du+1 && dfs(M[v])) {
            M[u] = v, M[v] = u;
            return true;
        }
    return false;
}

int hopcroft_karp() {
    FILL(M, 0);
    int matching = 0;
    while (bfs())
        REP(i, 1, n) 
            if (!M[i] && dfs(i))
                ++matching;
    return matching;
}

int main() {    
    int ne;
    RD(n, m, ne);


    REP(i, 1, ne) {
        int u, v; 
        RD(u, v);
        if (v>m) continue;
        e[u].PB(n+v), e[n+v].PB(u);
    }

    printf("%d\n", hopcroft_karp());

    return 0;
}