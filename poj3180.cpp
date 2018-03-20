#include <vector>
#include <cstring>
#define PB(x)       push_back(x)
#define RAN(i,a,b)  for(int i=(a); i<=(b); ++i)
#define RANI(i, x)  for (int i=0; i+1<=(x).size(); ++i)
#define RANR(i,a,b) for(int i=(a); i>=(b); --i)
#define RANIR(i,x)  for(int i=(x).size()-1; i>=0; --i)
#define FILL(x, a)  memset(x, a, sizeof(x))
#define SZ(x)       (int)((x).size())
using namespace std;

const int MAXN = 10007;

int n, m;
vector<int> e[MAXN], et[MAXN];

void dfs(int x, vector<int> e[], vector<int>& a, int color[]) {
    color[x] = 1;
    RANI(i, e[x])
        if (!color[e[x][i]])        
            dfs(e[x][i], e, a, color);
    a.PB(x);
}

int main() {
    scanf("%d %d", &n, &m);

    RAN(i, 1, m) {
        int x, y;
        scanf("%d %d", &x, &y);
        e[x].PB(y);
        et[y].PB(x);
    }

    int color[MAXN];
    FILL(color, 0);
    vector<int> ord;

    RAN(i, 1, n) if (!color[i]) dfs(i, e, ord, color);

    FILL(color, 0);
    int ans = 0;
    RANIR(i, ord)
        if (!color[ord[i]]) {
            vector<int> scc;
            dfs(ord[i], et, scc, color);
            if (SZ(scc)>1) ++ans;
        }
    printf("%d\n", ans);

    return 0;
}