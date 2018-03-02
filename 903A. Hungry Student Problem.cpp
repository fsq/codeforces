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
    while (n--) {
        int t;
        scanf("%d", &t);
        bool ok = false;
        for (int i=0; 3*i<=t; ++i)
            if (((t-3*i) % 7)==0) {
                ok = true;
                break;
            }
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}