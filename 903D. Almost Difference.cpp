#include <vector>
#include <cstdio>
#include <iomanip>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);
    unordered_map<long long, int> cnt;

    vector<long double> a;
    long double j;
    for (int i=0; i<n; ++i) {
        scanf("%Lf\n", &j);
        a.push_back(j);
    }

    long double sum = 0;
    long double ans = 0;
    for (int i=n-1; i>=0; --i) {
        sum = sum + a[i];
        ++cnt[a[i]];

        ans = ans + sum + (- (n-i)*a[i]);
        if (cnt.find(a[i]+1)!=cnt.end()) 
            ans = ans + (- cnt[a[i]+1]);
        if (cnt.find(a[i]-1)!=cnt.end())
            ans = ans + cnt[a[i]-1];
    }
    printf("%.0Lf\n", ans);
    return 0;
}