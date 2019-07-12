#include <iostream>
#include <string>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  if (n == k) {
    cout << string(n, '1') << endl;
    return 0;
  }
  if (k == 1) {
    string ans(n, '1');
    ans[0] = '0';
    cout << ans << endl;
    return 0;
  }
  for (int t=1; t<=n; ++t)
    for (int x=(n-t)/t; (t+1)*x+t>=n; --x) 
      if (t+(t-1)*x>=k && (t-1)+(t-2)*x<k) {
        int b = n - t*(x+1);
        int l = (t-2) * (x+1) + b + 2;
        if (l == k) {
          string ans(n, '0');
          for (int i=n-b-1; i>=0; i-=x+1) 
            ans[i] = '1';
          cout << ans << endl;
          return 0;
        }
      }
  return 0;
}