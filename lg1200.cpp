#include <string>
#include <iostream>

using namespace std;

string a, b;

int main() {
    cin >> a >> b;
    
    int x=1, y=1;

    for (auto c : a) x *= (c-'A'+1);
    for (auto c : b) y *= (c-'A'+1);

    cout << (x%47==y%47 ? "GO" : "STAY") << endl;

    return 0;
}