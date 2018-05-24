#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int n, m, a[103], f[103];

int main() {
    scanf("%d %d", &n, &m);
    stack<int> q;
    int ans = 0;
    for (int i=1; i<=n; ++i) {
        for (int x,j=1; j<=m; ++j) {
            scanf("%d", &x);
            a[j] = x ? a[j]+1 : 0;
        }
        
        for (int j=1; j<=m+1; ++j) {
            while (!q.empty() && a[j]<=a[q.top()]) {
                f[q.top()] += j - q.top() - 1;
                int len = min(a[q.top()], f[q.top()]);
                ans = max(ans, len);
                q.pop();
            }
            f[j] = q.empty() ? j : j-q.top();
            q.push(j);
        }
        q.pop();
    }

    printf("%d\n", ans);
    return 0;
}