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

int maxx(int a, int b, int c, int d, int e) {
    return max(e, max(max(a, b), max(c, d)));
}

int main() {
    int m, n;
    RD(m, n);

    VI w(n+1), v(n+1);
    VVI son(n+1);
    VI a;
    REP(i, 1, n) {
        int fa;
        RD(w[i], v[i]); 
        v[i] *= w[i];
        RD(fa);
        if (fa) 
            son[fa].PB(i);
        else
            a.PB(i);
    }

    VI f(m+1, 0); int ans = 0;
    FOREACH(x, a) 
        PER(j, m, 0) {
            f[j] = maxx(f[j], 
                        j-w[x]>=0? f[j-w[x]]+v[x] : 0, 
        SZ(son[x])>0 && j-w[x]-w[son[x][0]]>=0 ? 
                f[j-w[x]-w[son[x][0]]]+v[x]+v[son[x][0]] : 0, 
        SZ(son[x])>1 && j-w[x]-w[son[x][1]]>=0 ? 
                f[j-w[x]-w[son[x][1]]]+v[x]+v[son[x][1]] : 0,
        SZ(son[x])>1 && j-w[x]-w[son[x][0]]-w[son[x][1]] >=0 ?
                f[j-w[x]-w[son[x][0]]-w[son[x][1]]] + v[x]+v[son[x][0]]+v[son[x][1]]:0);
        ans = max(ans, f[j]);
    }


    printf("%d\n", ans);
    return 0;
}