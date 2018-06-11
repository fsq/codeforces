#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b) {
    if (a<b) return gcd(b, a);
    return b==0 ? a : gcd(b, a%b);
}

bool finite(long long p, long long q, long long b) {
    p %= q;
    if (!p) return true;

    long long d = gcd(p, q);
    p /= d, q /= d;
    
    for (long long d=gcd(q, b); d!=1; d=gcd(q, b)) 
        while (q%d==0) q/=d;
    
    return q==1;
}

int main() {
    int t;
    scanf("%d", &t);

    {
        long long p, q, b;
        while (t--) {
            scanf("%lld %lld %lld", &p, &q, &b);
            if (finite(p,q,b))
                printf("Finite\n");
            else
                printf("Infinite\n");
        }
    }

    return 0;
}