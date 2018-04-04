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

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);

    VI s(n+1, 0), c(n+1, 0); // s[i]:initial state of i:1 in, -1 not in, 0 NA
                             // c[i]:if i could be a leader: 1 yes, 0 no
    vector<PII> ops;

    char op; int x, cnt=0;
    int first_in = 0;

    unordered_set<int> in, out; // set of ids in/out of the room
                                // all are candidates

    REP(i, 1, m) {
        scanf("%c %d\n", &op, &x);
        if (op=='+') {
            if (s[x]==0) s[x] = -1; // x initially not in room
            if (!first_in) first_in = x; 
        } else {
            if (s[x]==0) {          // x initially in room
                s[x] = c[x] = 1;    // x is potentially a leader
                in.insert(x);       
                ++cnt;
            }
        }
        ops.PB({op=='+'?1:-1, x});
    }

    VI ans;

    // all those not shown in the sequence could be a leader
    REP_IF(i, 1, n, s[i]==0) c[i] = 1;

    // not one initially in the room, so the first added one could be a leader
    if (cnt==0 && first_in) {   
        c[first_in] = s[first_in] = 1;
        in.insert(first_in);
        cnt = 1;
        ops.erase(ops.begin());
    }

    FOREACH(&o, ops) {
        int op = o.F, x = o.S;
        if (op==1) {
            ++cnt;
            if (c[x]==1) { 
                out.erase(x);
                in.insert(x);
            } else {    
        // cnt>0, so those who curntly not in the room could not be the leaders
                FOREACH(i, out) c[i] = 0;
                out.clear();
            }
        } else {
            --cnt;
            if (c[x]==1) {
                // if after erasing x, cnt>0, x could not be a leader
                if (cnt>0) c[x] = 0; 
                else {
                    in.erase(x);
                    out.insert(x);
                }
            }
        }
    }
    // last state
    if (cnt>0) 
        FOREACH(i, out) c[i] = 0;
    

    REP_IF(i, 1, n, c[i]==1) ans.PB(i);
    printf("%d\n", SZ(ans));
    FOREACH(x, ans) printf("%d ", x); printf("\n");


    return 0;
}