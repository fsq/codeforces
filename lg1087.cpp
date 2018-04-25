#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> a;

void dfs(const string& s, int l, int r) {
    if (l>r) return;
    if (r>l)
        dfs(s, l, (r+l)>>1), dfs(s, ((r+l)>>1)+1, r);
    int cnt = a[r] - a[l-1];
    if (cnt==r-l+1) 
        printf("I"); 
    else if (cnt==0)
        printf("B");
    else
        printf("F");
}

int main() {
    int n;
    string s;

    cin >> n >> s;
    n = 1 << n;

    s.insert(s.begin(), ' ');
    a.resize(n+1);
    for (int i=1; i<=n; ++i) a[i] = a[i-1] + (s[i]=='1');
    dfs(s, 1, n);
    return 0;
}