#include <cstdio>
#include <algorithm>

using namespace std;

bool col[31], l[31], r[31];
int n, cnt;

void dfs(int d, int a[]) {
    if (d==n) {
        if (++cnt<=3) {
            for (int i=0; i<n; ++i) printf("%d ", a[i]);
            printf("\n");
        }
    } else {
        for (int i=0; i<n; ++i)
            if (!col[i] && !l[d+i] && !r[d+n-i-1]) {
                col[i] = l[d+i] = r[d+n-i-1] = true;
                a[d] = i+1;
                dfs(d+1, a);
                col[i] = l[d+i] = r[d+n-i-1] = false;
            }
    }
}

int main() {
    scanf("%d", &n);

    int a[n];
    dfs(0, a);
    printf("%d\n", cnt);
    
    return 0;
}