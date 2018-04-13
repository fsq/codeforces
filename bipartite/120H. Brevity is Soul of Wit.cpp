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
#include <fstream>
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

const int MAXN = 203;
const int INF  = 0x3f3f3f3f;
int n;
int d[MAXN];
string M[MAXN];
vector<string> e[MAXN];
unordered_map<string, int> Mr;

void proc(const int id, string& s, const string& a, int p) {
    if (p==a.size())
        if (s.size()>0 && s.size()<=4) e[id].PB(s); else {}
    else {
        proc(id, s, a, p+1);

        if (s.size()<4) {
            s.PB(a[p]);
            proc(id, s, a, p+1);
            s.pop_back();
        }
    }
}

bool bfs() {
    queue<int> q;
    REP(i, 1, n) 
        if (M[i].empty()) 
            d[i] = 0, q.push(i);
        else 
            d[i] = INF;
    d[0] = INF;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (d[u]<d[0])
            FOREACH(&v, e[u])
                if (d[Mr[v]]==INF) {
                    d[Mr[v]] = d[u] + 1;
                    q.push(Mr[v]);
                }
    }
    return d[0] != INF;
}

bool dfs(int u) {
    if (!u) return true;
    int dt = d[u];
    d[u] = INF;
    FOREACH(v, e[u])
        if (d[Mr[v]]==dt+1 && dfs(Mr[v])) {
            M[u] = v;
            Mr[v] = u;
            return true;
        }
    return false;
}


int main() {
    ifstream in("input.txt");
    in >> n;
    string s;
    REP(i, 1, n) {
        in >> s;
        if (s.size()<=4) {
            e[i].PB(s);
            continue;
        }
        string t;
        t.reserve(10);
        proc(i, t, s, 0);
    }
    int ans = 0;
    while (bfs()) 
        REP(i, 1, n) 
            if (M[i].empty() && dfs(i))
                ++ans;
    ofstream out("output.txt");
    if (ans==n) 
        REP(i, 1, n)
            out << M[i] << '\n';
    else
        out << -1 << '\n';

    return 0;
}