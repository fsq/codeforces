#include <vector>
#include <iostream>
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
    string s;
    cin >> s;

    int n = SZ(s);
    VI ca(n+1, 0), cb(n+1, 0);

    FORI(i, s) {
        ca[i+1] = ca[i] + (s[i]=='a');
        cb[i+1] = cb[i] + (s[i]=='b');
    }

    int ans = n;
    REP(l, 1, n)
        REP(r, l, n+1) {
            int bx = cb[l-1];
            int am = ca[r-1] - ca[l-1];
            int by = cb[n] - cb[r-1];
            ans = min(ans, bx+am+by);
        }

    // printf("%d\n", ans);
    cout << n-ans << endl;

    return 0;
}