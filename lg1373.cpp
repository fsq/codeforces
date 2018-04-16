#include <cstdio>
#include <cstring>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int n, m, k;
const int NN = 803;
const int MD = 1e9 + 7;
int a[NN][NN], f[NN][NN][20];

inline void add(int &x, int y) { (x+=y) %= MD; }

void trans(int i, int j, int x, int y, int w) {
    int nw = (w-a[x][y]+k) % k;
    REP(c, 0, k-1) 
        if (f[i][j][c]) 
            add(f[x][y][(c+nw+k) % k], f[i][j][c]);
}

int main() {
    scanf("%d %d %d", &n, &m, &k);++k;
    REP(i, 1, n)
        REP(j, 1, m) scanf("%d", &a[i][j]);
    int ans = 0;
    REP(i, 1, n)
        REP(j, 1, m) {   
            add(ans, f[i][j][0]);
            if (j+1<=m) 
                // add(f[i][j+1][(a[i][j]-a[i][j+1]+k) % k], 1);
                ++f[i][j+1][(a[i][j]-a[i][j+1]+k) % k];
            if (i+1<=n) 
                // add(f[i+1][j][(a[i][j]-a[i+1][j]+k) % k], 1);
                ++f[i+1][j][(a[i][j]-a[i+1][j]+k) % k];
            if (i+2<=n) trans(i, j, i+2, j, a[i+1][j]);
            if (j+2<=m) trans(i, j, i, j+2, a[i][j+1]);
            if (i+1<=n && j+1<=m) {
                trans(i, j, i+1, j+1, a[i+1][j]);
                trans(i, j, i+1, j+1, a[i][j+1]);
            }
        }

    printf("%d\n", ans);
    return 0;
}