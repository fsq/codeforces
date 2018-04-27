#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> name(n);
    vector<int> ori(n);
    for (int i=0; i<n; ++i) 
        cin >> ori[i] >> name[i];
    int p = 0;
    for (int a,s,i=0; i<m; ++i) {
        cin >> a >> s;
        int sign = a==ori[p] ? -1 : 1;
        p = (p + sign*s + n) % n;
    }
    cout << name[p] << endl;
    return 0;
}