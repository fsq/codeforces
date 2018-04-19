#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 50007;

int a[MAXN];
int n,l,m;

bool ok(int dis) {
    int left = m;
    int i = 0, j = 1;
    while (i<n+1) {
        if (a[j]-a[i]>=dis)
            i = j, ++j;
        else {
            while (j<=n && left && a[j]-a[i]<dis) {
                --left;
                ++j;
            }
            if (j<=n+1 && a[j]-a[i]>=dis)
                i = j, ++j;
            else if (left) 
                return true;
            else
                return false;
        }
    }
    return i==n+1;
}

int main() {
    scanf("%d %d %d", &l, &n, &m);
    a[n+1] = l;
    for (int i=1; i<=n; ++i) 
        scanf("%d", &a[i]);
    
    int lf = 1, rt = l;

    while (lf<rt) {
        int md = lf + ((rt-lf) >> 1);
        if (ok(md)) {
            lf = md;
            if (rt==lf+1) {
                if (ok(rt)) lf = rt;
                break;
            } 
        } else 
            rt = md - 1;
    }

    printf("%d\n", lf);
    return 0;
}