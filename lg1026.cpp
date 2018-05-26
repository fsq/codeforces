#include <string>
#include <iostream>
#include <algorithm>

#define REP(i,a,b) for(int i=(a);i<=(b);++i)

using namespace std;

int k, d, l;
string s[7];
string a;

int g[203][203];
int f[203][43];

void init() {
    int p;
    cin >> p >> k;
    string t;
    REP(i, 1, p) {
        cin >> t;
        a += t;
    }
    l = a.size();

    cin >> d;
    REP(i, 0, d-1) cin >> s[i];
}

void preprocess() {
    for (int j=l-1; j>=0; --j)
        for (int i=j; i>=0; --i) {
            g[i][j] = g[i+1][j];
            if (any_of(s, s+d, [&](const string& s) {
                return i+s.size()<=j+1 && equal(s.begin(), s.end(), a.begin()+i);
            }))  
                ++g[i][j];   
        }
}

int main() {
    init();
    preprocess();

    REP(i, 0, l-1) {
        f[i][1] = g[0][i];
        REP(j, 2, min(i+1, k)) 
            REP(p, j-2, i-1)
                f[i][j] = max(f[i][j], f[p][j-1] + g[p+1][i]);
    }
    printf("%d\n", f[l-1][k]);

    return 0;
}