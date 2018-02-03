#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    double min_pre = 101, a, b;
    while (n--) {
        cin >> a >> b;
        min_pre = min(min_pre, a/b);
    }
    // cout << m * min_pre << endl;
    printf("%.8f\n", m*min_pre);
    return 0;
}