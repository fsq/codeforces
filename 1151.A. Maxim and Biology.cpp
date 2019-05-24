#include "stdc++.h"

string g = "ACTG";

int f(const string& s, int i) {
  int ans = 0;
  for (int j=0; j<4; ++j)
    ans += min(abs(g[j]-s[i+j]), 26-abs(g[j]-s[i+j]));
  return ans;
}

int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = INT_MAX;
  for (int i=0; i+4<=n; ++i) 
    ans = min(ans, f(s, i));
  cout << ans << endl;
  return 0;
}