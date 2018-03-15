#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#define cind(x) scanf("%d", &x)

using namespace std;

int main() {
    int n;
    cind(n);
    vector<int> a;
    for (int j, i=0; i<n; ++i) {
        cind(j);
        a.push_back(j);
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end())-a.begin());

    int ans = a.size();
    if (a[0]==0) --ans;
    printf("%d\n", ans);

    return 0;
}