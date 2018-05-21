#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<pair<int,int>> a;

int main() {
    scanf("%d %d", &m, &n);
    for (int p,c,i=0; i<n; ++i) {
        scanf("%d %d", &p, &c);
        a.push_back({p, c});
    }

    sort(a.begin(), a.end());

    int ans = 0;
    for (int i=0; i<a.size() && m>0; ++i) {
        int buy = min(m, a[i].second);
        ans += a[i].first * buy;
        m -= buy;
    }

    printf("%d\n", ans);

    return 0;
}