#include <algorithm>
#include <cstdio>
#include <cmath>
#include <numeric>
#include <climits>
#include <cstring>

using namespace std;

using PII = pair<int, int>;
PII a[5007];
bool vis[5007];
double e[5007];

const double INF = 100000000000000;

inline double dist(const PII& a, const PII& b) {
    return (double)(a.first-b.first)*(a.first-b.first) + 
            (double)(a.second-b.second)*(a.second-b.second);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i=1; i<=n; ++i)
        scanf("%d %d", &a[i].first, &a[i].second);

    double ans = 0;

    vis[1] = true;
    for (int i=1; i<=n; ++i) e[i] = dist(a[1], a[i]);

    for (int _t=1; _t<n; ++_t) {
        double mind = INF;
        int u = 0;
        for (int i=1; i<=n; ++i)
            if (!vis[i] && e[i]<mind) {
                u = i;
                mind = e[i];
            }
            ans += sqrt(mind);
            vis[u] = true;
            for (int i=1; i<=n; ++i) {
                double dd = dist(a[u], a[i]);
                if (!vis[i] && e[i]>dd)
                    e[i] = dd;
            }
    }

    printf("%.2f", round(ans*100)/100);

    return 0;
}