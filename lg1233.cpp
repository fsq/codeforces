#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
using PII = pair<int,int>;

int n;
vector<PII> a;

int main() {
    scanf("%d", &n);
    for (int x,y,i=0; i<n; ++i) {
        scanf("%d %d", &x, &y);
        a.emplace_back(x, y);
    }
    sort(a.begin(), a.end());

    vector<int> f(n, 1);
    for (int i=1; i<n; ++i)
        for (int j=0; j<i; ++j) 
            if (a[i].second<a[j].second)
                f[i] = max(f[i], f[j]+1);
    printf("%d\n", *max_element(f.begin(), f.end()));
    return 0;
}