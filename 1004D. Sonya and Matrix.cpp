#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int t;
int a[1000007], b[1000007];

void build(int n, int m, int r, int c, int b[]) {
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            ++b[abs(i-r)+abs(j-c)];
}

bool ok(int b[]) {
    for (int i=0; i<=t; ++i)
        if (a[i]!=b[i]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t;

    int mx = 0;
    for (int x,i=0; i<t; ++i) {
        cin >> x;
        mx = max(x, mx);
        ++a[x];
    }

    if (t==1) {
        if (a[0]==1) {
            cout << "1 1\n1 1" << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }

    {
        bool line = true;
        for (int i=0; i<t; ++i)
            if (a[i]!=1) {
                line = false;
                break;
            }
        if (line) {
            cout << 1 <<' ' << t << "\n1 1" << endl;
            return 0;
        }
    }

    int x=-1, y=-1, i, j=0;
    for (i=1; a[i] ;++i)
        if (a[i]!=i*4) {
            if (a[i]+2==i*4) x = i, y = i;
                        else     x = i;
            break;
        }

    if (y==-1) {
        for (++i; a[i]==a[i-1]+2;++i);
        y = i;
    }

    // cout << x << ' ' << y << endl;
    bool found = false;

    if (!(x==-1 || y==-1)) {
        // case 1
        int c1 = -1, c2 = mx+x+y, c3 = -t;
        int delta2 = c2*c2 - 4*c1*c3;
        if (delta2>=0 && pow((int)sqrt(delta2), 2)==delta2) {
            int delta = sqrt(delta2);
            vector<double> ms = {(-c2-delta) / (2.0*c1), (-c2+delta) / (2.0*c1)};
            for (auto m : ms) 
                if (m>0 && m==floor(m) && t%(int)m==0) {
                    int n = t / m;
                    memset(b, 0, sizeof(b));
                    build(n, m, x, y, b);
                    if (ok(b)) {
                        found = true;
                        cout << n << ' ' << m << '\n' << x << ' ' << y << endl;
                        break;
                    }
                    memset(b, 0, sizeof(b));
                    build(n, m, y, x, b);
                    if (ok(b)) {
                        found = true;
                        cout << n << ' ' << m << '\n' << y << ' ' << x << endl;
                        break;
                    }

                }

        }

        // case 2
        if (!found) {
            int n = x + y - 1;
            if (t%n==0) {
                if (x<y) swap(x, y);
                int m = t / n;
                memset(b, 0, sizeof(b));
                // printf("%d %d %d %d\n", n,m,x, mx-x+2);
                build(n, m, x, (mx-x+2), b);
                // for (int i=0; i<=t; ++i)
                    // cout << b[i] << ' ';cout << endl;
                if (ok(b)) {
                    found = true;
                    cout << n << ' ' << m << '\n' << x << ' ' << (mx-x+2) << endl;    
                }
            }
        }
    }

    if (!found)
        cout << -1 << endl;

    
    return 0;

}