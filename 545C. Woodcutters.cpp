#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> x, h;
    long long t;
    for (int i=0; i<n; ++i) {
        cin >> t;
        x.push_back(t);
        cin >> t;
        h.push_back(t);
    }
    x.push_back(INT_MAX);
    int count = 0;
    long long pre = INT_MIN;

    for (int i=0; i<n; ++i) 
        if (x[i]-h[i]>pre) {
            ++count;
            pre = x[i];
        } else if (x[i]+h[i]<x[i+1]) {
            ++count;
            pre = x[i]+h[i];
        } else 
            pre = x[i];
    cout << count << endl;
    return 0;
}