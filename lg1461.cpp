#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, b, d;
    cin >>n >> b >> d;
    vector<int> a = {0};
    for (int i=1; a.size()<n; ++i) {
        if (all_of(a.begin(), a.end(), [=](int x) {
            return __builtin_popcount(x^i)>=d;
        })) 
            a.push_back(i);
    }

    for (int h=0, i=0; i<n; ++i) {
        cout << a[i] << ' ';
        if (++h==10) {
            cout << '\n';
            h = 0;
        }
    }

    return 0;
}