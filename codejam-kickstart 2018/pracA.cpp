#include <iostream>
#include <vector>

using namespace std;

int main() {
 	int t;
 	cin >> t;
 	for (int p,n,_t=1; _t<=t; ++_t) {
 		cout << "Case #"<<_t<<": ";
 		cin >> n;
 		vector<int> a(n), b(n);
 		for (int i=0; i<n; ++i) cin >> a[i] >> b[i];
  		
  		cin >> p;
  		vector<int> c(p);
  		for (int i=0; i<p; ++i) cin >> c[i];

  		for (auto x : c) {
  			int cnt = 0;
  			for (int i=0; i<n; ++i)
  				if (a[i]<=x && x<=b[i])
  					++cnt;
  			cout << cnt << ' ';
  		}
  		cout << '\n';

 	}

    return 0;
}

