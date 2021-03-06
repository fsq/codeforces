#include <cstdio>
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
using namespace std;

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

using PII = pair<int,int>;
using LL  = long long;
using VI  = vector<int>;
using VLL = vector<LL>;
using VVI = vector<VI>;

const int M = 1e9 + 7;

LL pw(int p) {
    LL res = 1, x = 2;
    while (p) {
        if (p&1) res = res*x % M;
        p >>= 1;
        x = x*x % M;
    }
    return res;
}

void add(LL& x, LL v) {
    x = (x+v) % M;
    if (x<0) x += M;
}

int main() {

    LL x, y;
    RD(x, y);

    if (y%x != 0)
        printf("0\n");
    else {
        y /= x;
        VLL d;
        LL i;
        for (i=1; i*i<y; ++i)
            if (y%i==0) 
                d.PB(i), d.PB(y/i);
        if (i*i==y) d.PB(i);
        sort(ALL(d));

        VLL f = VLL(SZ(d), 0);
        f[0] = 1;
        for (int i=1; i<SZ(d); ++i) {
            f[i] = pw(d[i]-1);
            FOR(j, i)
                if (d[i]%d[j]==0)
                    add(f[i], -f[j]);
        }
        printf("%lld\n", f.back());
    }









    return 0;
}