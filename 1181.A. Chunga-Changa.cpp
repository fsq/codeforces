#include "stdc++.h"

int main() {
  LL x, y, z;
  cin >> x >> y >> z;
  LL n = (x+y) / z, g = 0;
  if (x/z+y/z != n)
    g = min((z-x%z)%z, (z-y%z)%z);
  cout << n << ' ' << g << endl;
  return 0;
}