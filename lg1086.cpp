#include <vector>
#include <cstdio>
#include <algorithm>
#include <functional>
#define ALL(a) (a).begin(),(a).end()
using namespace std;

vector<vector<int>> a;

int main() {
    int n, m, T;
    scanf("%d %d %d", &n, &m, &T);
    for (int i=1; i<=n; ++i)
        for (int c,j=1; j<=m; ++j) {
            scanf("%d", &c);
            if (c>0)
                a.push_back({c, i, j});
        }
    sort(ALL(a), greater<vector<int>>());

    int ans = 0, t = 0, x=0, y=0;
    for (auto& p : a) {
        int dis = (x==0 ? p[1] : abs(x-p[1])+abs(y-p[2])) + 1 + p[1];
        if (t+dis<=T) {
            t += (x==0 ? p[1] : abs(x-p[1])+abs(y-p[2])) + 1;
            x = p[1], y = p[2];
            ans += p[0];
        } else
            break;
    }
    printf("%d\n", ans);

    return 0;
}