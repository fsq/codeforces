#include <iostream>
#include <algorithm>

using namespace std;

int f[50][50];

int main() {
    int n, m;
    cin >> n >> m;
    f[0][0] = 1;
    for (int i=1; i<=m; ++i)
        for (int j=0; j<n; ++j)
            f[i][j] = f[i-1][(j+1)%n] + f[i-1][(j-1+n)%n];
    cout << f[m][0] << endl;
    return 0;
}