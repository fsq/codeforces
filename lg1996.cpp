#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n, 1);
    int c = 0, out = 0, i = 0;
    while (out<n) {
        if (a[i] && ++c==m) {
            a[i] = 0;
            printf("%d ", i+1);
            ++out;
            c = 0;
        }
        i = (i+1) % n;
    }

    return 0;
}