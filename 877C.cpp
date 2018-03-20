#include <vector>
#include <cstdio>
#define PB(x) push_back(x)

using namespace std;

// f[n] = l+1, l, f[n-2], l+1

void solve(vector<int>& ans, int l, int r) {
    int len = r-l+1;
    if (len==1)
        ans.PB(l);
    else if (len==2) {
        ans.PB(r);
        ans.PB(l);
        ans.PB(r);
    } else {
        ans.PB(l+1);
        ans.PB(l);
        solve(ans, l+2, r);
        ans.PB(l+1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> ans;
    solve(ans, 1, n);
    printf("%d\n", ans.size());
    for (auto x : ans) printf("%d ", x);
    return 0;
}