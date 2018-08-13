#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int gcd(int x, int y) {
    return y==0 ? x : gcd(y, x%y);
}

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> a;
    for (int i=1; i<=n; ++i)
        for (int j=0; j<=i; ++j)
            if (gcd(i, j)==1) 
                a.push_back({j, i});
    sort(a.begin(), a.end(), [](pair<int,int>& a, pair<int,int>& b) {
        return a.first*b.second < b.first*a.second;
    });
    for (auto& p : a) 
        cout << p.first << "/" << p.second << '\n';
    return 0;
}