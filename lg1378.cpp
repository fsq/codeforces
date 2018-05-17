#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
using PDD = pair<double, double>;
const double PI = 3.1415926;
int n;
vector<PDD> a;
double x, y, xt, yt;

double dist(const PDD& a, const PDD& b) {
    return sqrt(pow(a.first-b.first, 2)+pow(a.second-b.second, 2));
}

double dfs(int i, const vector<PDD>& a, vector<double>& r) {
    if (i==a.size()) return 0;
    r[i] = min(min(a[i].first-x, xt-a[i].first), min(a[i].second-y, yt-a[i].second));
    for (int j=0; j<i; ++j) 
        r[i] = min(r[i], dist(a[j], a[i])-r[j]);
    r[i] = max(r[i], 0.0);
    return PI*pow(r[i],2) + dfs(i+1, a, r);
}

int main() {
    scanf("%d %lf %lf %lf %lf", &n, &x, &y, &xt, &yt);
    a.resize(n);
    for (int i=0; i<n; ++i) scanf("%lf %lf", &a[i].first, &a[i].second);

    if (x > xt) swap(x, xt);
    if (y > yt) swap(y, yt);

    sort(a.begin(), a.end());

    double max_area = 0;
    vector<double> r(n);
    do {
        max_area = max(max_area, dfs(0, a, r));
    } while (next_permutation(a.begin(), a.end()));

    printf("%d\n", (int)round((xt-x)*(yt-y) - max_area));
    return 0;
}