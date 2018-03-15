#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <ctime>
#define cind(x) scanf("%d", &x)

using namespace std;

int p, y;


bool isPrime(int x) {
    if (x==2) return true;
    for (int i=2; i<=min<int>(p, sqrt(x)); ++i)
        if (x % i==0)
            return false;
    return true;
}


int main() {
    srand(time(NULL));
    cind(p), cind(y);
    int ans = -1;
    for (int i=y; i>p; --i) 
        if (isPrime(i)) {
            ans = i;
            break;
        }

    printf("%d\n", ans);

    return 0;
}