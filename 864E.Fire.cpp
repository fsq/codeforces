#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 107;
const int MAXD = 2007;

int f[MAXN][MAXD], g[MAXN][MAXD];
int t[MAXN], d[MAXN], p[MAXN], ind[MAXN], pre[MAXN];

void sswap(int i, int j) {
    swap(t[i], t[j]);
    swap(d[i], d[j]);
    swap(p[i], p[j]);
    swap(ind[i], ind[j]);
}

void sort(int l, int r) {
    int i=l, j=r, x=d[(l+r)>>1];
    do {
        while (d[i]<x) ++i;
        while (d[j]>x) --j;
        if (i<=j) {
            sswap(i, j);
            ++i;
            --j;
        } 
    } while (i<=j);
    if (i<r) sort(i, r);
    if (l<j) sort(l, j);
}

int main() {
    int n;
    scanf("%d", &n);
    memset(f, 0, sizeof(f));

    int maxd = -1;
    for (int i=1; i<=n; ++i) {
        scanf("%d %d %d\n", &t[i], &d[i], &p[i]);
        pre[i] = t[i];
        ind[i] = i;
        maxd = max(maxd, d[i]);
    }

    sort(1, n);

    for (int i=1; i<=n; ++i) {
        // printf("%d %d %d\n", t[i], d[i], p[i]);
        for (int j=1; j<=t[i]; ++j) {
            f[i][j] = f[i-1][j];
            g[i][j] = j;
        }
        for (int j=t[i]+1; j<=d[i]; ++j) 
            if (f[i-1][j] > f[i-1][j-t[i]]+p[i]) {
                f[i][j] = f[i-1][j];
                g[i][j] = j;
            } else {
                f[i][j] = f[i-1][j-t[i]] + p[i];
                g[i][j] = -ind[i];
            }
        
        for (int j=d[i]+1; j<=maxd; ++j) 
            if (f[i][j-1] > f[i-1][j]) {
                f[i][j] = f[i][j-1];
                g[i][j] = 0;
            } else {
                f[i][j] = f[i-1][j];
                g[i][j] = j;
            }
        
    }
    printf("%d\n", f[n][maxd]);

    vector<int> a;
    int i=n, j=maxd;
    while (i>0 && j>0) {
        if (g[i][j]==0)
            --j;
        else if (g[i][j]==j)
            --i;
        else {
            int id = -g[i][j];
            a.push_back(id);
            --i;
            j -= pre[id];
        }
    }

    printf("%d\n", a.size());
    for (int i=a.size()-1; i>=0; --i)
        printf("%d ", a[i]);
    printf("\n");


    return 0;
}