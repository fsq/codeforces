#include <cstdio>

using namespace std;

long long a, b, k;

long long pow(long long x) {
    if (x==0) return 1 % k;
    if (x==1) return a % k;
    long long b = pow(x>>1);
    if (x&1) return (b*b % k) * a % k;
        else return (b*b % k);
}

int main() {
    scanf("%lld %lld %lld", &a, &b, &k);
    long long s = 1, ans = 1;
    printf("%lld^%lld mod %lld=", a, b, k);
    
    printf("%lld\n", pow(b));

    return 0;
}