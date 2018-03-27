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

pair<LL, LL> count(LL x) {
    if (x==1) return {1, 1};
    auto pr = count(x>>1);
    return {pr.F<<1 | 1, pr.S<<1 | (x & 1)};
}

LL f(LL n, LL x) {
    if (x==0 || n==0) return 0;
    if (n==1 || x==1) return 1;
    pair<LL, LL> lb = count(n>>1); 
    if (x<=lb.F) 
        return f(n>>1, x); 
    else if (lb.F+1==x) 
        return lb.S + (n&1);
    else 
        return lb.S + (n&1) + lb.S-f(n>>1, 2*lb.F-x+1);
}

int main() {

    LL n, l, r;
    RD(n, l, r);

    LL a = f(n, r), b = f(n, l-1);
#ifdef ONLINE_JUDGE
    printf("%I64d\n", a-b);
#else 
    printf("%lld\n", a-b);
#endif


    return 0;
}