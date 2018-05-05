#include <vector>
#include <cstdio>
#include <cmath>
#define F first
#define S second

using namespace std;


int n;
const double INF = 10000000000;
using PFF = pair<double, double>;
PFF a[203];
double f[203][203];
double far[203];
double setfar[203];
double fa[203];

double dist(const PFF& a, const PFF& b) {
    return sqrt((a.F-b.F)*(a.F-b.F) + (a.S-b.S)*(a.S-b.S));
}

int find(int x) { return fa[x]==x ? x : fa[x]=find(fa[x]); }
void merge(int i, int j) { fa[find(i)] = find(j); }

int main() {
    scanf("%d\n", &n);
    if (n==1) {
        printf("0.000000\n");
        return 0;
    }

    for (int i=1; i<=n; ++i) {
        scanf("%lf %lf\n", &a[i].first, &a[i].second);
        fa[i] = i;
    }

    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            char c;
            scanf("%c", &c);
            c -= '0';
            if (c==1) {
                f[i][j] = dist(a[i], a[j]);
                merge(i, j);
            } else
                f[i][j] = INF;
        }
        scanf("\n");
    }

    for (int k=1; k<=n; ++k)
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=n; ++j)
                if (i!=j)
                    f[i][j] = min(f[i][j], f[i][k]+f[k][j]);

    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j)
            if (f[i][j]!=INF)
                far[i] = max(far[i], f[i][j]),
        setfar[find(i)] = max(setfar[find(i)], far[i]);        
    }

    double ans = INF;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            if (find(i)!=find(j))
                ans = min(ans, 
                        max(far[i]+far[j]+dist(a[i], a[j]),
                            max(setfar[find(i)],setfar[find(j)])));
    printf("%.6lf\n", ans);
    return 0;
}