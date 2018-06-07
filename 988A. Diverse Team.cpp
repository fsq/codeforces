#include <cstdio>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, k;

int main() {
    scanf("%d %d", &n, &k);
    unordered_map<int, int> map;

    for (int x,i=1; i<=n; ++i) {
        scanf("%d", &x);
        map[x] = i;
    }
    
    if (map.size()<k)
        printf("NO\n");
    else {
        printf("YES\n");
        auto it = map.begin();
        for (auto i=0; i<k; ++it, ++i)
            printf("%d ", it->second);
        printf("\n");
    }


    return 0;
}