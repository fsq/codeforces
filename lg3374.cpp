#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> s;

inline int lowbit(int x) { return x & -x; }

void add(int i, long long y) {
    for (; i<s.size(); i+=lowbit(i)) s[i] += y;
}

long long sum(int i) {
    long long ret = 0;
    for (; i; i-=lowbit(i)) 
        ret += s[i];
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    s.resize(n+1);
    for (int x,i=1; i<=n; ++i) {
        cin >> x;
        add(i, x);
    }
    for (int c,x,y; m; --m) {
        cin >> c >> x >> y;
        if (c==1) 
            add(x, y);
        else
            cout << sum(y)-sum(x-1) << '\n';
    }
    return 0;
}