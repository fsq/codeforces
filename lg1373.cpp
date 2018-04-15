#include <cstdio>
#include <cstring>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int n, m, k;
const int NN = 803;
const int MD = 1e9 + 7;
int a[NN][NN], f[NN][NN][63];

inline void add(int &x, int y) {
    x += y;
    if (x>=MD) x-=MD;
}

void trans(int i, int j, int x, int y, int w, int v) {
    REP(c, -(k<<1), (k<<1)) 
        if (f[i][j][c+(k<<1)]) {
            int nw = c + w - v;
        }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    REP(i, 1, n)
        REP(j, 1, m) scanf("%d", &a[i][j]);

    REP(i, 1, n)
        REP(j, 1, m) {  
            if (i-2>0) trans(i-2, j, i, j, a[i-1][j], a[i][j]);
            if (j-2>0) trans(i, j-2, i, j, a[i][j-1], a[i][j]);
            if (i-1>0 && j-1>0) {
                trans(i-1, j-1, i, j, a[i-1][j], a[i][j]);
                trans(i-1, j-1, i, j, a[i][j-1], a[i][j]);
            }
            add(f[i][j][0], 1);
        }
    return 0;
}