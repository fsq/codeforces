#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    priority_queue<int, vector<int>, std::greater<int>> q;
    for (int x,i=0; i<n; ++i) {
        scanf("%d", &x);
        q.push(x);
    }

    int ans = 0;
    while (q.size()>1) {
        int s = 0;
        s += q.top(), q.pop();
        s += q.top(), q.pop();
        ans += s;
        q.push(s);
    }
    printf("%d\n", ans);
    return 0;
}