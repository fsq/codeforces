#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// f[i][h] = first i, height h, max remaining time
// f[i][h] = f[i-1][h-h[i]] - inter[i-1][i]
//           f[i-1][h] - inter[i-1][i] + t[i]

class obj {
public:
    int t, f, h;
    obj(int _t, int _f, int _h) : 
        t(_t), f(_f), h(_h) {}
};

int main() {
    int d, g;
    scanf("%d %d", &d, &g);

    vector<obj> a;
    for (int t,h,f,i=1; i<=g; ++i) {
        scanf("%d %d %d", &t, &f, &h);
        a.emplace_back(t,f,h);
    }

    sort(a.begin(), a.end(), [](const obj& a, const obj& b){ return a.t<b.t; });
    a.insert(a.begin(), obj(0,0,0));
    vector<vector<int>> f(g+1, vector<int>(d+30, -1));
    f[0][0] = 10;
    int mx = 10;
    for (int i=1; i<=g; ++i)
        for (int j=0; j<=d+25; ++j) {
            f[i][j] = -1;

            if (j-a[i].h>=0 && f[i-1][j-a[i].h]>=a[i].t)
                f[i][j] = f[i-1][j-a[i].h];
            if (f[i-1][j]>=a[i].t)
                f[i][j] = max(f[i][j], f[i-1][j] + a[i].f);

            mx = max(mx, f[i][j]);
            if (f[i][j]>=a[i].t && j>=d) {
                printf("%d\n", a[i].t);
                return 0;
            }
        }

    printf("%d\n", mx);
    return 0;
    
    
}