#include <vector>
#include <cstdio>
#include <cstring>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i, a) for(int i=0; i<(a); ++i)
using namespace std;
int n, m;
int a[101][101];

class Num {
public:
    int a[40];
    int len = 40;
    Num() { memset(a, 0, sizeof(a)); }

    void add(const Num& b) {
        FOR(i, len) {
            a[i] += b.a[i];
            if (a[i]>=10) {
                a[i+1] += a[i]/10;
                a[i] %= 10;
            }
        }
    }

    void times(int b) {
        FOR(i, len) a[i] *= b;
        FOR(i, len) 
            if (a[i]>=10) {
                a[i+1] += a[i]/10;
                a[i] %= 10;
            }
    }

    bool operator< (const Num& b) {
        for (int i=len-1; i>=0; --i)
            if (a[i] != b.a[i])
                return a[i]<b.a[i];
        return true;
    }

    void print() {
        int i = len-1;
        while (i>=0 && a[i]==0) --i;
        if (i<0)
            printf("0\n");
        else 
            for (;i>=0; --i) printf("%d", a[i]);printf("\n");
    }
};

Num pow[82];

Num dp(int a[]) {
    Num f[m+3][m+3];
    REP(i, 1, m) {
        f[i][i] = pow[m];
        f[i][i].times(a[i]);
    }

    REP(l, 2, m)
        for (int i=1; i+l-1<=m; ++i) {
            int j = i+l-1;
            auto x = pow[m-j+i], y = pow[m-j+i];
            x.times(a[i]), y.times(a[j]);
            x.add(f[i+1][j]), y.add(f[i][j-1]);

            f[i][j] = x<y ? y : x;
        }
    return f[1][m];
}

int main() {
    scanf("%d %d", &n, &m);
    REP(i, 1, n) 
        REP(j, 1, m) scanf("%d", &a[i][j]);

    pow[0].a[0] = 1;
    REP(i, 1, m) {
        pow[i] = pow[i-1];
        pow[i].times(2);
    }

    Num ans;
    REP(i, 1, n)
        ans.add(dp(a[i]));

    ans.print();
    return 0;
}