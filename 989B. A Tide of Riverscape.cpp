#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, p;
string s;

int main() {
    
    cin >> n >> p >> s;

    if (p>=n) 
        cout << "NO" << endl;
    else {
        bool valid = true;
        for (int i=0; i<p; ++i) {
            int len = 0, zero = 0, one = 0, dot = 0;
            vector<int> pos;
            for (int j=i; j<n; j+=p) {
                ++len;
                if (s[j]=='.') {
                    ++dot;
                    if (pos.size()<2) pos.push_back(j);
                } else if (s[j]=='1') 
                    ++ one;
                else 
                    ++ zero;
            }
            if (len>1 && (dot || zero*one)) {
                if (dot==1) {
                    if (! (zero*one) )
                        s[pos[0]] = zero ? '1' : '0';
                } else if (dot>1) {
                    s[pos[0]] = '1';
                    s[pos[1]] = '0';
                }
                valid = false;
                break;
            }
        }
        if (valid) 
            cout << "NO" << endl;
        else {
            for (auto& c : s) if (c=='.') c = '0';
            cout << s << endl;
        }
    }

    return 0;
}