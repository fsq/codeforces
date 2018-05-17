#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <functional>
#include <cstring>

using namespace std;

int n;
vector<int> a;

bool ok(int i, vector<int>& buckets, const int cap) {
    if (i==n) return true;

    bool vis[cap+1];
    memset(vis, false, sizeof(vis));
    for (auto &bucket : buckets) {
        if (bucket<cap && bucket+a.back()>cap) return false;
        if (!vis[bucket]) {
            vis[bucket] = true;
            if (bucket+a[i]<=cap) {
                bucket += a[i];
                if (ok(i+1, buckets, cap))
                    return true;
                bucket -= a[i];
            }
        }
    }
    return false;
}

int main() {
    int l=INT_MAX, r=INT_MAX, s=0;
    scanf("%d", &n);
    for (int x,i=0; i<n; ++i) {
        scanf("%d", &x);
        if (x<=50) {
            a.push_back(x); 
            l = min(l, x);
            r = max(r, x);
            s += x;
        }
    }
    sort(a.begin(), a.end(), std::greater<int>()); 
    n = a.size();

    for (; l<=r; ++l)
        if (s % l==0) {
            vector<int> buckets(s/l);
            if (ok(0, buckets, l)) {
                printf("%d\n", l);
                break;
            }
        }

    return 0;
}