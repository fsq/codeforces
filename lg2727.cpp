#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

long long comb(long long a, long long b) {
    if (a-b<b) b = a - b;
    long long ans = 1;
    for (int i=1; i<=b; ++i)
        ans = ans * (a-i+1) / i;
    return ans;
}

long long f(int n, int l) {
    // if (l>=n) return 1ll<<n;
    l = min(l, n);
    long long ans = 0;
    for (int i=0; i<=l; ++i)
        ans += comb(n, i);
    return ans;
}

string build(int n, int l, long long m) {
    if (m==(1<<n)) return string(n, '1');
    if (m==1) return string(n, '0');
    if (n==1)
        return m==1 ? "0" : "1";
    long long cnt = f(n-1, l);
    // printf("comb(%d, %d)=%lld %lld\n", n-1, l, cnt, m);
    return cnt>=m ? "0"+build(n-1, l, m) : "1"+build(n-1, l-1, m-cnt);
}

int main() {
    int n, l;
    long long m;
    cin >> n >> l >> m;
    cout << build(n, l, m) << endl;

    return 0;
}