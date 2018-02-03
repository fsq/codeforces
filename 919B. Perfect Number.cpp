#include <iostream>
#include <string>

using namespace std;

int main() {
    int k;
    cin >> k;

    string s = "19";

    while (k>1) {
        int sum = 0;
        bool changed = false;
        for (int i=s.size()-1; i>=0; --i) 
            if (sum>0 && s[i]<'9') {
                ++s[i];
                s.back() = sum - 1 + '0';
                changed = true;
                break;
            } else {
                sum += s[i] - '0';
                s[i] = '0';
            }
        if (!changed) {
            s = '1' + s;
            s.back() = sum - 1 + '0';
        }
        --k;
    }
    cout << s << endl;
    return 0;
}