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

int sc[5][5] = {{0, -3,-4,-2,-1},{-3,5,-1,-2,-1},{-4,-1,5,-3,-2},
                {-2,-2,-3,5,-2},{-1,-1,-2,-2,5}};

int score(int x, int y) {
    return sc[x][y];
}

int main() {
    int n, m;
    string s, t;
    cin >> n >> s >> m >> t;
    // printf("%d %d\n", s.size(), t.size());
    VI a(n+1, 0), b(m+1, 0);
    REP(i, 0, n-1) 
        if (s[i]=='A') a[i+1] = 1;
        else if (s[i]=='C') a[i+1] = 2;
        else if (s[i]=='G') a[i+1] = 3;
                    else    a[i+1] = 4;
    REP(i, 0, m-1)
        if (t[i]=='A') b[i+1] = 1;
        else if (t[i]=='C') b[i+1] = 2;
        else if (t[i]=='G') b[i+1] = 3;
                    else    b[i+1] = 4;


    VVI f(n+1, VI(m+1, INT_MIN));
    f[0][0] = 0;
    REP(i, 1, n) f[i][0] = f[i-1][0] + score(a[i], 0);
    REP(i, 1, m) f[0][i] = f[0][i-1] + score(0, b[i]);
    REP(i, 1, n)
        REP(j, 1, m) {
            f[i][j] = f[i-1][j-1] + score(a[i], b[j]);
            f[i][j] = max(f[i][j], 
                          max(f[i-1][j]+score(a[i],0), f[i][j-1]+score(0,b[j])));
        }
    cout << f[n][m] << endl;
    return 0;
}