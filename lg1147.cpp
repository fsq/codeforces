#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    n <<= 1;
    vector<pair<int,int>> ans;
    for (int i=sqrt(n); i>=2; --i) 
        if (n%i==0) {
            int b = i - 1;
            if ((n/i-b)%2==0)
                cout << (n/i-b)/2 << ' ' << (n/i-b)/2+b << '\n';
        }
    
    return 0;
}