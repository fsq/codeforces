#include "stdc++.h"

string add(string a, string b) {
  reverse(ALL(a));
  reverse(ALL(b));
  int c = 0;
  for (int i=0; i<SZ(a); ++i) {
    a[i] = (a[i]-'0') + (i<SZ(b) ? (b[i]-'0') : 0) + c;
    c = a[i] / 10;
    a[i] %= 10;
    a[i] += '0';
  }
  if (c)
    a.PB('1');
  reverse(ALL(a));
  return a;
}

string min(const string& a, const string& b) {
  if (SZ(a) < SZ(b))
    return a;
  else if (SZ(a) > SZ(b))
    return b;
  else
    return min<string>(a, b);
}

int main() {
  int n;
  string s;
  cin >> n >> s;

  string a, b;
  for (int i=(n+1)/2; i<SZ(s); ++i)
    if (s[i] != '0') {
      a = add(s.substr(0, i), s.substr(i));
      break;
    }
  for (int i=(n+1)/2-1; i>0; --i)
    if (s[i] != '0') {
      b = add(s.substr(i), s.substr(0, i));
      break;
    }
  cout << (a.empty() ? b : (b.empty() ? a : min(a, b))) << endl;
  return 0;
}