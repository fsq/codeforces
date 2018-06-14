#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    long double x, y;
    cin >> x >> y;
    long double a = y*log10(x), b = x*log10(y);

    if (abs(a-b)<1e-6) 
        cout << '=' << endl;
    else if (a>b)
        cout << '>' << endl;
    else
        cout << '<' << endl;

    return 0;
}