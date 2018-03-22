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
#include <deque>

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
using VLL = vector<long long>;
using VVI = vector<vector<int>>;

const int MAXN = 100007;
int n, c;

LL mn[MAXN], a[MAXN];

int main() {

    // O(n)
    
    RD(n, c);
    REP(i, 1, n) RD(a[i]);

    VLL s(n+3, 0);
    partial_sum(a+1, a+n+1, s.begin()+1);

    int start = 1;
    deque<int> q;
    REP(end, 1, n) {
        if (end-c>0)
            while (!q.empty() && q.front()<=end-c)
                q.pop_front();

        while (!q.empty() && a[q.back()] >= a[end])
            q.pop_back();

        q.push_back(end);
        mn[end] = a[q.front()];
    }

    LL f[MAXN];
    f[0] = 0;
    REP(i, 1, n) {
        f[i] = f[i-1] + a[i];
        if (i>=c)
            f[i] = min(f[i], f[i-c]+s[i]-s[i-c]-mn[i]);
    }


#ifdef ONLINE_JUDGE
    printf("%I64d\n", f[n]);
#else 
    printf("%lld\n", f[n]);
#endif


    return 0;
}