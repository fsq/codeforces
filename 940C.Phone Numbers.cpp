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

#define BACK(x)     *prev((x).end(), 1)
#define FRONT(x)    *(x).begin()

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
    int n, k;
    RD(n, k);

    char a[100007];
    set<char> st;
    REP(i, 1, n) {
        RD(a[i]);
        st.insert(a[i]);
    }

    if (k>n) {
        REP(i, n+1, k) a[i] = FRONT(st);
    } else {
        char mxc = BACK(st);
        PER(i, k, 1)
            if (a[i]!=mxc) {
                a[i] = *st.upper_bound(a[i]);
                REP(j, i+1, k) a[j] = FRONT(st);
                break;
            }
    }

    REP(i, 1, k) printf("%c", a[i]);
    printf("\n");

    return 0;
}