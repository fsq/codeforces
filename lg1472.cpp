#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n, k;
const int M = 9901;

vector<vector<int>> f;

int df(int n, int k) {
    if (n==0) return 1;
    if (n==1) return k>=1;
    if (f[n][k]!=-1) return f[n][k];
    if (k==0) return 0;

    f[n][k] = 0;
    for (int i=1; i+1<n; ++i)
        f[n][k] = (f[n][k] + df(i,k-1) * df(n-1-i,k-1)) % M;
    printf("f[%d][%d]=%d\n", n,k,f[n][k]);
    return f[n][k];
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    f = vector<vector<int>>(n+3, vector<int>(k+3, -1));
    
    cout << (df(n, k)+M-df(n, k-1)) % M << endl;
    return 0;
}