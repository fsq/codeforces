#include <vector>
#include <algorithm>
#include <cstdio>
#include <functional>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int,int>> a(n);
    for (int x,i=0; i<n; ++i) {
        scanf("%d", &a[i].first);
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());

    double s = 0, pre = 0;
    for (int i=0; i<n; ++i) {
        printf("%d ", a[i].second);
        s += pre;
        pre += a[i].first;
    }


    printf("\n%.2lf\n", s/n);

    return 0;
}