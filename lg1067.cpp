#include <cstdio>
#include <iostream>
#include <future>
#include <string>
#include <vector>
using namespace std;

string f(int p, int c) {
    if (c==0) return "";
    string tc = abs(c)==1 && p!=0? "" : to_string(abs(c));
    string sc = c>0 ? "+"+tc : "-"+tc;
    return p>0 ? sc+(p==1?"x" : "x^"+to_string(p)) : sc;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n+1);
    for (int i=0; i<=n; ++i) scanf("%d", &a[i]);

    // vector<future<string>> s;
    // for (int i=1; i<=n; ++i) s.push_back(async(f, n-i, a[i]));

    string ans = f(n, a[0]);
    if (ans[0]=='+') ans.erase(ans.begin());

    for (int i=1; i<=n; ++i) ans += f(n-i, a[i]);
    // for (auto &ft : s)
        // ans += ft.get();
    cout << ans << endl;

    return 0;
}