#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<string,int>> a(n);
    for (int i=0; i<n; ++i) cin >> a[i].first, a[i].second=i+1;

    sort(a.begin(), a.end(), [](const pair<string,int>& a, const pair<string,int>& b) {
        return a.first.size()>b.first.size() || a.first.size()==b.first.size() && a.first>b.first;
    });

    cout << a[0].second << '\n' << a[0].first << endl;

    return 0;
}