#include <cstdio>

int a[41][41];
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int i=0, j=n/2;
    int set = 0;
    while (set<n*n) {
        a[i][j] = ++set;
        if (i==0) 
            if (j==n-1)
                ++i;
            else 
                i = n-1, ++j;
        else 
            if (j==n-1)
                j = 0, --i;
            else
                if (a[i-1][j+1]==0)
                    --i, ++j;
                else 
                    ++i;
    }
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) printf("%d ", a[i][j]);
            printf("\n");
    }

    return 0;
}