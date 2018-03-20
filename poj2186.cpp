#include <vector>
#include <cstring>
#define PB(x)       push_back(x)
#define FOR(i,a,b)  for(int i=(a); i<=(b); ++i)
#define FORI(i, x)  for (int i=0; i+1<=(x).size(); ++i)
#define ROF(i,a,b)  for(int i=(a); i>=(b); --i)
#define ROFI(i, x)  for(int i=(x).size()-1; i>=0; --i)
#define FOREACH(a, x) for (auto a : (x))
#define FILL(x, a)  memset(x, a, sizeof(x))
#define SZ(x)       (int)((x).size())
using namespace std;

const int MAXN = 10007;
const int MAXM = 50007;

vector<int> e[MAXN], et[MAXN];

int fa[MAXN], size[MAXN], od[MAXN];

void dfs(int x, vector<int> e[], vector<int>& a, int color[]) {
    color[x] = 1;
    FORI(i, e[x])
        if (!color[e[x][i]])
            dfs(e[x][i], e, a, color);
    a.PB(x);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    FOR(i, 1, m) {
        int x, y;
        scanf("%d %d", &x, &y);
        e[x].PB(y);
        et[y].PB(x);
    }

    vector<int> ord;
    int color[MAXN];
    FILL(color, false);
    FOR(i, 1, n) 
        if (!color[i]) 
            dfs(i, e, ord, color);

    FILL(color, false);
    ROFI(i, ord) 
        if (!color[ord[i]]) {
            vector<int> scc;
            dfs(ord[i], et, scc, color);
            FORI(k, scc) {
                fa[scc[k]] = ord[i];
                ++size[ord[i]];
            }
        }

    FOR(i, 1, n)
        FORI(j, e[i])
            if (fa[i]!=fa[e[i][j]]) 
                ++od[fa[i]];

    int cand, cnt=0;
    FOR(i, 1, n) 
        if (fa[i]==i && od[i]==0) {
            ++cnt;
            cand = i;
            if (cnt>1) break;
        }

    printf("%d\n", cnt==1 ? size[cand] : 0);

    return 0;
}