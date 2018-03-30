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

int n, m;
string s;
vector<PII> f;

void update(char c, int i, vector<int>& cnt, int v) {
    if (c=='a') 
        cnt[1^(i&1)] += v;
    else if (c=='b') 
        cnt[2 + (1^(i&1))] += v;
}

int main() {
    RD(n);
    f = vector<PII>(n+1, PII(0, 0));

    s = string(n+1, '?');
    REP(i, 1, n) RD(s[i]);
    RD(m);
    m = min(m, n);

    vector<int> cnt(4, 0);

    REP(i, 1, m)
        update(s[i], i, cnt, 1);

    if (cnt[1]==0 && cnt[2]==0) 
        f[m] = {1, m-cnt[0]-cnt[3]};

    REP(i, m+1, n) {
        update(s[i-m], 1, cnt, -1);
        swap(cnt[0], cnt[1]);
        swap(cnt[2], cnt[3]);
        update(s[i], m, cnt, 1);

        auto pre = f[i-1];
        PII now = {0, 0};
        if (cnt[1]==0 && cnt[2]==0) 
            now = {f[i-m].F+1, f[i-m].S+m-cnt[0]-cnt[3]};
        if (now.F>pre.F || (now.F==pre.F && now.S<pre.S))
            f[i] = now;
        else
            f[i] = pre;
    }

    printf("%d\n", f.back().S);

    return 0;
}