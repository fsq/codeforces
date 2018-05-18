#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define REP(i,a,b) for (int i=(a);i<=(b);++i)

using namespace std;

int n, m;
int a[507][507];
int reach[507]; // can reach the last row ?
bool cover[507]; // a[1][i] can be covered by another a[1][j]
bool vis[507][507];
vector<vector<int>> set;

int ans = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int r, int c, const int src) {
    vis[r][c] = true;
    if (r==1 && c!=src) cover[c] = true;
    REP(dir, 0, 3) {
        int tx=r+dx[dir], ty=c+dy[dir];
        if (tx>=1 && tx<=n && ty>=1 && ty<=m && !vis[tx][ty] && a[tx][ty]<a[r][c])
            dfs(tx, ty, src);
    }
}

void process_set() {
    vector<int> st[m+1];
    REP(i, 1, m) 
        if (!cover[i]) {
            memset(vis, false, sizeof(vis));
            dfs(1, i, i);

            vector<int> s;
            REP(j, 1, m)
                if (vis[n][j]) {
                    s.push_back(j);
                    ++reach[j];
                }
            st[i] = move(s);
        }
    REP(i, 1, m) 
        if (!cover[i])
            set.push_back(move(st[i]));
}

int seg_cover(vector<vector<int>> &a) {
    sort(a.begin(), a.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0]<b[0] || (a[0]==b[0] && a.back()>b.back());
    });

    int cnt = 0, r = 0;
    for (int i=0; r<m && i<a.size(); ) {
        int maxr = r;
        while (i<a.size() && a[i][0]<=r+1) {
            maxr = max(maxr, a[i].back());
            ++i;
        }
        ++cnt;
        r = maxr;
    }
    return cnt;
}

int main() {
    scanf("%d %d", &n, &m);
    REP(i, 1, n)
        REP(j, 1, m)
            scanf("%d", &a[i][j]);

    process_set();

    int imp = 0;
    REP(i, 1, m) 
        if (!reach[i])
            ++imp;

    if (imp) 
        printf("0\n%d\n", imp);
    else 
        printf("1\n%d\n", seg_cover(set));
    

    return 0;
}