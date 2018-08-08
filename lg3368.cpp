#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
long long s[500006];
int n, m;

inline int lowbit(int x) { return x & -x; }

void add(int i, long long x) {
    for (; i<=n; i+=lowbit(i)) s[i] += x;
}

long long sum(int i) {
    long long ret = 0;
    for (; i>0; i-=lowbit(i)) ret += s[i];
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int x,i=1; i<=n; ++i) {
        cin >> x;
        add(i, x);
        add(i+1, -x);
    }
    for (int c,x,y,k; m; m--) {
        cin >> c;
        if (c==1) {
            cin >> x >> y >> k;
            add(x, k);
            add(y+1, -k);
        } else {
            cin >> x;
            cout << sum(x) << '\n';
        }
    }
    return 0;
}