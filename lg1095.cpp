#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
int m, s, t, d;

int main() {
    cin >> m >> s >> t;
    int dt = t;
    while (t && d<s) {
        if (m>=10) {
            d += 60;
            m -= 10;
            --t;
            if (d>=s) break;
        } else {
            int r = ceil((10-m)/4.0);
            if (d+17*(r+1)>=s) {
                while (d<s) --t, d+=17;
                break;
            }
            if (t > r) {
                t -= r + 1;
                m = m + 4*r - 10;
                d += 60;
            } else {
                d += t * 17;
                t = 0;
            }
        }
    }

    if (d>=s) 
        cout << "Yes\n" << dt -t << endl;
    else
        cout << "No\n" << d << endl;
        
    return 0;
}