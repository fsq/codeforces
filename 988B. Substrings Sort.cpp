#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> a;
int n;

bool sub(const string& a, const string& b) {
    return b.find(a) != string::npos;
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i=0; i<n; ++i) cin >> a[i];

    for (int i=0; i<n; ++i)
        for (int j=i+1; j<n; ++j)
            if (!sub(a[i], a[j]) && !sub(a[j],a[i])) {
                cout << "NO" << endl;
                return 0;
            }
    cout << "YES" << endl;
    sort(a.begin(), a.end(), [](const string& a, const string& b) {
        return sub(a, b);
    });

    for (auto& s : a) cout << s << '\n';
    return 0;
}