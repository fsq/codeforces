#include <vector>
#include <cstring>
#define pb(x) push_back(x)
#define RANGE(i,a,b) for(int i=(a); i<=(b); ++i)
#define RANGER(i,a,b) for(int i=(a); i>=(b); --i)
#define FILL(x, a) memset(x, a, sizeof(x))
using namespace std;

const int MAXN = 1007;

int n, m;
vector<int> e[MAXN], et[MAXN];

void dfs(int x, vector<int> e[], vector<int>& a, int color[]) {
    color[x] = 1;
    for (auto nxt : e[x])
        if (!color[nxt]) 
            dfs(nxt, e, a, color);
    a.pb(x);
}

int main() {
    scanf("%d %d", &n, &m);

    RANGE(i, 1, m) {
        int x, y;
        scanf("%d %d", &x, &y);
        e[x].pb(y);
        et[y].pb(x);
    }

    int color[MAXN];
    FILL(color, 0);
    vector<int> ord;

    RANGE(i, 1, n) if (!color[i]) dfs(i, e, ord, color);

    FILL(color, 0);
    vector<vector<int> > sccs;
    RANGER(i, ord.size()-1, 0) 
        if (!color[ord[i]]) {
            vector<int> scc;
            dfs(ord[i], et, scc, color);
            sccs.pb(scc);
        }

    int ans = 0;
    for (auto& s : sccs) {
        for (auto x : s) printf("%d ", x);
        printf("\n");
    }

    return 0;
}