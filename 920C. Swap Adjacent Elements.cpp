#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a = {0};
    for (int j,i=1; i<=n; ++i) {
        cin >> j;
        a.push_back(j);
    }
    string s;
    cin >> s;
    int i = 0;
    bool valid = true;
    while (i<s.size()) 
        if (s[i]=='1') {
            int j = i;
            // a[i+1, j+1] should contain [i+1, j-1]
            int maxelem = INT_MIN, minelem = INT_MAX;
            while (j<s.size() && s[j]=='1') {
                maxelem = max(maxelem, a[j+1]);
                minelem = min(minelem, a[j+1]);
                ++j;
            }
            maxelem = max(maxelem, a[j+1]);
            minelem = min(minelem, a[j+1]);
            if (maxelem==j+1 && minelem==i+1) 
                i = j + 1;
            else {
                valid = false;
                break;
            }
        } else {
            if (a[i+1]!=i+1) {
                valid = false;
                break;
            }
            ++i;
        }
    cout << (valid ? "YES": "NO") << endl;


    return 0;
}