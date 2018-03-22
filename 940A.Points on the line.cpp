#include <vector>
#include <cstdio>
#include <cstring>
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
    int n, d;
    RD(n,d);

    int a[1001];
    REP(i, 1, n) RD(a[i]);

    sort(a+1, a+n+1);

    int ans = n-1;
    REP(i, 1, n) 
        PER(j, n, i) 
            if (a[j]-a[i]<=d) {
                ans = min(ans, n - (j-i+1));
                break;
            }
    

    printf("%d\n", ans);

    return 0;
}