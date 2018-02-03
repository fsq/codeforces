// scanf is much more faster than cin
// almost 10 times

#include <iostream>
#include <vector>

using namespace std;

int n, q, c;
const int N = 101;
vector<vector<vector<int>>> f(N, vector<vector<int>>(N, vector<int>(11, 0)));

void init() {
    cin >> n >> q >> c;

    for (int i=0,x,y,s; i<n; ++i) {
        scanf("%d%d%d\n", &x, &y, &s);
        ++f[x][y][s];
    }
    for (int i=1; i<N; ++i)
        for (int j=1; j<N; ++j)
            for (int k=0; k<=c; ++k)
                f[i][j][k] = f[i][j][k] + f[i-1][j][k] + f[i][j-1][k] - f[i-1][j-1][k];
}

int main() {
    init();
    int t, x1, y1, x2, y2;
    while (q--) {
        scanf("%d%d%d%d%d\n", &t, &x1, &y1, &x2, &y2);
        int sum = 0;
        for (int b=0; b<=c; ++b) {
            int brightness = (b + t) % (c + 1);
            if (brightness==0) continue;
            int count = f[x2][y2][b] - f[x1-1][y2][b] - f[x2][y1-1][b] + f[x1-1][y1-1][b];
            sum += count * brightness;
        }
        printf("%d\n", sum);
    }
    return 0;
}