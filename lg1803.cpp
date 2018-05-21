#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int,int>> a;

int main() {
    scanf("%d", &n);
    for (int l,r,i=0; i<n; ++i) {
        scanf("%d %d", &l, &r);
        a.push_back({l, r});
    }

    sort(a.begin(), a.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.second < b.second;
    });

    int cnt = 0, end = 0;
    for (auto& p : a)
        if (p.first>=end) {
            end = p.second;
            ++cnt;
        }
    printf("%d\n", cnt);
    return 0;
}