#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, ans=0;
	cin >> n;
	vector<char> a(n);
	for (int i=0; i<n; ++i) cin >> a[i];

	for (int c,l,i=0; i<n; ++i) {
		c = a[(i+1)%n];
		l = 2;
		for (int j=(i+2)%n; j!=(i+1)%n; j=(j+1)%n, ++l)
			if (c=='w')
				c = a[j];
			else if (a[j]!='w' && c!=a[j]) 
				break;

		c = a[i%n];
		for (int j=(i-1+n)%n; j!=i; j=(j-1+n)%n, ++l)
			if (c=='w')
				c = a[j];
			else if (a[j]!='w' && c!=a[j])
				break;
		ans = max(ans, min(l, n));
	}

	cout << ans << endl;

	return 0;
}