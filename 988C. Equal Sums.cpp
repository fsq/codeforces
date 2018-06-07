#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int n;
unordered_map<int, pair<int,int>> map;


int main() {
    scanf("%d", &n);
    vector<int> sum(n);

    for (int i=0; i<n; ++i) {
        int s = 0, ni;
        scanf("%d", &ni);

        vector<int> a(ni);
        for (int j=0; j<ni; ++j) {
            scanf("%d", &a[j]);
            s += a[j];
        }

        for (int j=0; j<ni; ++j) 
            if (map.find(s-a[j])==map.end()) 
                map[s-a[j]] = {i+1, j+1};
            else if (map[s-a[j]].first!=i+1) {
                printf("YES\n");
                printf("%d %d\n%d %d\n", map[s-a[j]].first, map[s-a[j]].second, i+1, j+1);
                return 0;
            }
    }

    printf("NO\n");


    return 0;
}