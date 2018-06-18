#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int n;
double x[21], y[21];
double d[21][21];
double ans;

double dist(int i, int j) {
    return sqrt(pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2));
}


void dfs(int now, double dis, int vis) {
    if (vis+1==(1<<n))
        ans = min(ans, dis);
    else {
        if (dis>=ans) return;
        for (int j=1; j<=n; ++j)
            if (!((vis>>(j-1)) & 1)) 
                dfs(j, dis+d[now][j], vis | (1<<(j-1)));
    }
}


int main() {
    cin >> n;
    for (int i=1; i<=n; ++i) cin >>x[i] >> y[i];
    for (int i=0; i<=n; ++i)
        for (int j=i+1; j<=n; ++j) 
            d[i][j] = d[j][i] = dist(i, j);
        

    for (int i=1; i<=n; ++i) ans += d[i-1][i];
    dfs(0, 0, 0);

    printf("%.2f\n", ans);


    return 0;
}