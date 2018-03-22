#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

#define PB(x)       push_back(x)
#define REP(i,a,b)  for(int i=(a); i<=(b); ++i)
#define PER(i,a,b)  for(int i=(a); i>=(b); --i)

#define FOR(i,n)    for (int i=0; i<(n); ++i)
#define FORI(i, x)  for (int i=0; i<(x).size(); ++i)
#define ROFI(i, x)  for(int i=(x).size()-1; i>=0; --i)

#define FOREACH(a, x) for (auto a : (x))
#define FILL(x, a)  memset(x, a, sizeof(x))
#define ALL(x)      (x).begin(), (x).end()
#define SZ(x)       (int)((x).size())

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
using VVI = vector<vector<int>>;

int main() {
    LL n, k, a, b;
    RD(n, k, a, b);

    LL cost = 0;

    if (k==1) cost = (n-1) * a;
    else 
        while (n!=1)  
            if (n%k==0) {
                LL nxt = n / k;
                cost += min(b, (n-nxt)*a);
                n = nxt;
            } else {
                LL nxt = max(1LL, n / k * k);
                cost += a * (n-nxt);
                n = nxt;
            }

#ifdef ONLINE_JUDGE
    printf("%I64d\n", cost);
#else
    printf("%lld\n", cost);
#endif

    return 0;
}