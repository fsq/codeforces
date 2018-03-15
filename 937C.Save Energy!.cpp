#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#define cind(x) scanf("%Lf", &x)

using namespace std;

int main() {
    long double k,d,t;
    cind(k), cind(d), cind(t);
    if (k>d) {
        long double pd = d;
        d = d * floor(k/pd);
        if (d<k) d += pd;
    }
    
    long double round = floor((2*t)/(k+d));
    long double rest = 2*t - (k+d)*round;
    long double rt = 0;
    if (rest<=2*k) 
        rt = rest / 2;
    else 
        rt = k + (rest-2*k);
    printf("%Lf\n", round*d + rt);
    return 0;
}