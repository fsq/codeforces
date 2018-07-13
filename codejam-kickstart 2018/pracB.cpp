#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(long long i, long long k) {
	if (i==1) return 0;
	if (k==(1ll<<(i-1))) 
		return 0;
	else if (k>(1ll<<(i-1)))
		return 1 ^ f(i-1, (1ll<<i)-k);
	else 
		return f(i-1, k);
}

int main() {
    
    int T;
    cin >> T;
 	long long k;
    for (int t=1; t<=T; ++t) {
    	cin >> k;
    	cout << "Case #" << t << ": " << f(61, k) << '\n';
    }

	return 0;
}