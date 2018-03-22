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
    int n;
    int a[100007];
    char b[100007];

    RD(n);
    REP(i, 1, n) RD(a[i]);
    REP(i, 1, n) RD(b[i]);

    int inf = 1000000001;
    int hir = inf, hil = inf;
    int lor = -inf, lol = -inf;

    REP(i, 5, n)
        if (b[i-1]==b[i-2] && b[i-2]==b[i-3] && b[i-3]==b[i-4]) {
            int mina = min(min(a[i], a[i-1]), min(a[i-2], min(a[i-3], a[i-4])));
            int maxa = max(max(a[i], a[i-1]), max(a[i-2], max(a[i-3], a[i-4])));
            if (b[i-1]=='1' && b[i]=='0')
                hir = min(hir, mina);
            else if (b[i-1]=='1' && b[i]=='1')
                lor = max(lor, mina-1);
            else if (b[i-1]=='0' && b[i]=='0')
                hil = min(hil, maxa+1);
            else 
                lol = max(lol, maxa);
        }
    printf("%d %d\n", lol+1, hir-1);
        
    return 0;
}