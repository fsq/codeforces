#include <vector>
#include <cstdio>
#include <cmath>
#define F first
#define S second

using namespace std;


int n;
const float INF = 10000000000;
using PFF = pair<float, float>;
PFF a[203];
float f[203][203];
float far[203];
float fa[203];

float dist(const PFF& a, const PFF& b) {
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
        scanf("%f %f\n", &a[i].first, &a[i].second);
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

    for (int i=1; i<=n; ++i) 
        for (int j=1; j<=n; ++j)
            if (f[i][j]!=INF)
                far[i] = max(far[i], f[i][j]);
    // for (int i=1; i<=n; ++i) printf("%f\n", far[i]);
    float ans = INF;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            if (find(i)!=find(j))
                ans = min(ans, far[i]+far[j]+dist(a[i], a[j]));
    printf("%.6f\n", ans);
    return 0;
}