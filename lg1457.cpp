#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <numeric>

#define PB                  push_back
#define F                   first
#define S                   second

#define REP(i,from,to)      for(auto i=(from); i<=(to); ++i)
#define PER(i,from,to)      for(auto i=(from); i>=(to); --i)
#define REP_IF(i,from,to,assert)   for(auto i=(from); i<=(to); ++i) if (assert)

#define FOR(i,less_than)    for (auto i=0; i<(less_than); ++i)
#define FORI(i, container)  for (auto i=0; i<(container).size(); ++i)

#define FILL(container, value)    fill(container.begin(), container.end(), value)

using PII = std::pair<int,int>;
using LL  = long long;
using VI  = std::vector<int>;
using VLL = std::vector<LL>;        
using VVI = std::vector<VI>;

using namespace std;

int n, m;
vector<VVI> wall;
VI fa, sz;
int scc, max_sz;

vector<int> dx={0,-1,0,1};
vector<int> dy={-1,0,1,0};

inline bool ok(int x, int y) {
    return x>=0 && x<n && y>=0 && y<m;
}

int find(int x) { return fa[x]==x ? x : fa[x]=find(fa[x]); }

inline int encode(int x, int y) { return x*m+y+1; }

void merge(int x, int y, int tx, int ty) {
    int a = encode(x, y), b = encode(tx, ty);
    int fx=find(a), fy=find(b);
    if (fx!=fy) {
        --scc;
        fa[fx] = fy;
        sz[fy] += sz[fx];
        max_sz = max(max_sz, sz[fy]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> m >> n;
    wall = vector<VVI>(n+1, VVI(m+1, VI(4)));

    fa.resize(n*m+1);
    sz.resize(n*m+1);
    scc = n*m ,max_sz = 1;
    iota(fa.begin(), fa.end(), 0);
    FILL(sz, 1);

    REP(i, 0, n-1) REP(j, 0, m-1) {
        int x;
        cin >> x;
        REP(k, 0, 3) 
            wall[i][j][k] = (x>>k & 1);
        REP(k, 0, 3)
            if (!wall[i][j][k]) {
                 int tx=i+dx[k], ty=j+dy[k];
                 merge(i,j,tx,ty);
            }
    }

    cout << scc << '\n' << max_sz << '\n';

    int max_merge = 0;
    string direction = " NE ";
    string pos;
    FOR(j, m) PER(i, n-1, 0)  
        REP(k, 1, 2)
            if (wall[i][j][k]) {
                int tx=i+dx[k], ty=j+dy[k];
                if (ok(tx, ty)) {
                    int fx = find(encode(i,j)), fy = find(encode(tx,ty));
                    if (fx!=fy && sz[fx]+sz[fy]>max_merge) {
                        max_merge = sz[fx] + sz[fy];
                        pos = to_string(i+1) + " " + to_string(j+1) + " " + direction[k];
                    }
                }
            }

    cout << max_merge << '\n' << pos << endl;

    return 0;
}