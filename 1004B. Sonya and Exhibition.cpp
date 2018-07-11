#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) 
        cout << (i&1);
    cout << endl;

    return 0;
}