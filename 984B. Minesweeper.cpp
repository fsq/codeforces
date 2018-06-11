#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int a[103][103];

bool valid(int x, int y) {
    int cnt = 0;
    for (int i=x-1; i<=x+1; ++i)
        for (int j=y-1; j<=y+1; ++j)
            if (i>=0 && i<n && j>=0 && j<m && a[i][j]=='*')
                ++cnt;
    return cnt == a[x][y] - '0';
}

int main() {
    scanf("%d %d\n", &n, &m);

    {
        char c;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                scanf("%c", &c);
                if (c=='.') c = '0';
                a[i][j] = c;
            }
            scanf("\n");
        }
    }

    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            if (a[i][j]!='*' && !valid(i, j)) {
                printf("NO\n");
                return 0;
            }

    printf("YES\n");

    return 0;
}