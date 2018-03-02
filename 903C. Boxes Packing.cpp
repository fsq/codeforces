#include <vector>
#include <cstdio>
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

    unordered_map<int, int> m;
    int mx = -1;
    for (int j,i=0; i<n; ++i) {
        scanf("%d", &j);
        mx = max(++m[j], mx);
    }
    printf("%d\n", mx);

    return 0;
}