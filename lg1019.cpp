#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<string> a;

int link[23][23];

int linkable(const string& a, const string& b) {
    for (int i=0; i+1<b.size() && i+1<a.size(); ++i)
        if (equal(b.begin(), b.begin()+i+1, a.end()-i-1))
            return b.size() - i - 1;
    return 0;
}

int dfs(int now, vector<int>& use) {
    int ans = 0;
    for (int i=0; i<n; ++i)
        if (link[now][i] && use[i]<2) {
            ++use[i];
            ans = max(ans, link[now][i] + dfs(i, use));
            --use[i];
        }
    return ans;
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            link[i][j] = linkable(a[i], a[j]);
    char head;
    cin >> head;
    vector<int> use(n);
    int ans = 0;
    for (int i=0; i<n; ++i)
        if (a[i][0]==head) {
            ++use[i];
            ans = max<int>(ans, a[i].size() + dfs(i, use));
            --use[i];
        }
    cout << ans << endl;
    return 0;
}