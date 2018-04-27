#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n==1) {
        cout << 0 << endl;
        return 0;
    }
    int sum = 0;
    vector<int> a(n);
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    int avg = sum / n;
    int ans = 0;
    for (int i=0; i<n; ++i)
        if (a[i]!=avg) {
            ++ans;
            a[i+1] -= (avg - a[i]);
        }
    cout << ans << endl;
    return 0;
}