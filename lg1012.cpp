#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int x,i=0; i<n; ++i) {
        cin >> x;
        a[i] = to_string(x);
    }

    sort(a.begin(), a.end(), [](string& a, string& b) {
        return a+b > b+a;
    });

    for (auto& s : a) cout << s;
    cout << endl;


    return 0;
}