#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>

#define PB(x)               push_back(x)
#define F                   first
#define S                   second

#define REP(i,from,to)      for(int i=(from); i<=(to); ++i)
#define PER(i,from,to)      for(int i=(from); i>=(to); --i)

#define FOR(i,less_than)    for (int i=0; i<(less_than); ++i)
#define FORI(i, container)  for (int i=0; i<(container).size(); ++i)
#define ROFI(i, container)  for(int i=(container).size()-1; i>=0; --i)

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

using namespace std;
using LL  = long long;
using VI  = vector<int>;
using VLL = vector<LL>;
using VVI = vector<VI>;

int main() {

    int h, j;
    RD(h);

    VI a(h+1);
    REP(i, 0, h) {
        RD(j);
        a[i] = j;
    }
    // s : evenly distribute ith layer to i-1 th layers
    // t : append all ith layer to the first of i-1 the layer
    VI s = {0}, t = s;
    int l=1, r=1;
    REP(i, 1, h) {
        int now = l;
        REP(j, r+1, r+a[i]) {
            s.PB(now);
            if (++now>r) now = l;
            t.PB(l);
        }
        l = r + 1;
        r += a[i];
    }

    if (s==t) printf("perfect\n");
    else {
        printf("ambiguous\n");
        FOREACH(x, s) printf("%d ", x); printf("\n");
        FOREACH(x, t) printf("%d ", x); printf("\n");
    }

    return 0;
}