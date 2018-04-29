#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using PII = pair<int,int>;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> e(10);
    vector<PII> a(n); //score, index
    for (int i=0; i<10; ++i) cin >> e[i];
    for (int i=0; i<n; ++i) cin >> a[i].first, a[i].second = i+1;

    sort(a.begin(), a.end(), [](const PII&a, const PII& b) {
        return a.first>b.first || (a.first==b.first && a.second<b.second);
    });

    for (int i=0; i<n; ++i)
        a[i].first += e[i%10];

    sort(a.begin(), a.end(), [](const PII&a, const PII& b) {
        return a.first>b.first || (a.first==b.first && a.second<b.second);
    });

    for (int i=0; i<k; ++i)
        cout << a[i].second << ' ';
    cout << endl;


    return 0;
}