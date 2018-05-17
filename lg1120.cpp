#include <algorithm>
#include <cstdio>
#include <climits>
#include <functional>

using namespace std;

int n, num_buckets, cap;
// can't use vector
// the overhead tle last test case
// vector<int> a;
int a[100];
bool vis[80];

bool ok(int bid, int from, int sum) {
    if (bid==num_buckets-1) return true;
    if (sum==cap) return ok(bid+1, 0, 0);
    if (sum+a[n-1]>cap) return false;

    for (int i=from; i<n; ++i)
        if (!vis[i] && sum+a[i]<=cap) {
            vis[i] = true;
            if (ok(bid, i+1, sum+a[i])) return true;
            vis[i] = false;
            // !
            // if (sum+a[i]==cap) fails, we dont have to consider where smaller 
            // pieces fills the gap of size a[i]

            // if sum==0 and put a[i] fails
            // means a[i] can't be used in any empty bin, therefore all fails
            if (sum+a[i]==cap || sum==0) return false;
            while (i+1<n && a[i]==a[i+1]) ++i;
        }
    return false;
}

int main() {
    int l=INT_MIN, s=0;
    scanf("%d", &n);
    int nt = 0;
    for (int x,i=0; i<n; ++i) {
        scanf("%d", &x);
        if (x<=50) {
            a[nt++] = x;
            l = max(l, x);
            s += x;
        }
    }
    n = nt;
    sort(a, a+n, std::greater<int>()); 

    // if more than two stickers, length at most s/2
    for (; l<=s/2; ++l)
        if (s % l==0) {
            num_buckets = s / l;
            cap = l;
            if (ok(0, 0, 0)) {
                printf("%d\n", l);
                return 0;
            }
        }

    printf("%d\n", s);

    return 0;
}