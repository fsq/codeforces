#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    vector<string> a;
    string c;
    cin >> c;
    while (c!=".") {
        a.push_back(c);
        cin >> c;
    }

    string str;
    while (cin >> c) str += c;

    vector<int> f(str.size()+1);
    f[0] = 1;
    for (int i=1; i<=str.size(); ++i) 
        for (auto& s : a)
            if (i>=s.size() && equal(s.begin(), s.end(), str.begin()+i-s.size())
                            && f[i-s.size()]) {
                f[i] = 1;
                break;
            }
            
    for (int i=str.size(); i>=0; --i)
        if (f[i]) {
            cout << i << endl;
            break;
        }

    
    return 0;
}