#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n & 1)
    cout << 0 << endl;
  else 
    cout << (1l<<(n/2)) << endl;
  return 0;
}