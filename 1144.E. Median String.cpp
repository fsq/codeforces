#include "stdc++.h"

int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  reverse(ALL(s));
  reverse(ALL(t));
  for (int i=0; i<s.size(); ++i) {
    s[i] = s[i]-'a' + t[i]-'a';
    if (s[i] > 25) {
      s[i] -= 26;
      if (i+1==s.size()) 
        s.PB(1);
      else
        ++s[i+1];
    }
  }
  reverse(ALL(s));
  int c = 0;
  FOR(i, SZ(s)) {
    if (c) {
      s[i] += 26;
      c = 0;
    }
    c = s[i] & 1;
    s[i] = (s[i]>>1) + 'a';
  }
  cout << s.substr(SZ(s)-n) << endl;
  return 0;
}