#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

using VI = vector<int>;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n);

    for (int x,y,z,i=0; i<n; ++i) {
        cin >> x >> y >> z;
        a[i] = {x+y+z, x, i+1};
    }

    sort(a.begin(), a.end(), [](const VI&a, const VI& b) {
        return a[0]>b[0] || (a[0]==b[0] && a[1]>b[1]) 
                || (a[0]==b[0] && a[1]==b[1] && a[2]<b[2]);
    });

    for (int i=0; i<5; ++i)
        cout << a[i][2] << ' ' << a[i][0] << endl;

    return 0;
}