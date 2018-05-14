#include <vector>
#include <iostream>
#include <climits>

using namespace std;

int main() {

    int n, ans, f, x;
    cin >> n >> ans;
    f = ans;
    --n;
    while (n--) {
        cin >> x;
        f = max(f+x, x);
        ans = max(ans, f);
    }
    printf("%d\n", ans);
    return 0;
}