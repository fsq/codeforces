#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;
int n, m, r, k;

using TLLII = tuple<long long, int ,int>;

long long encode(int x, int y) {
    return (long long)x * 1e6 + y;
}

long long get_freq(int i, int j) {
    long long xlo = max(0, i-r+1), xhi = min(i, n-r);
    long long ylo = max(0, j-r+1), yhi = min(j, m-r);
    return max(0ll, xhi-xlo+1) * max(0ll, yhi-ylo+1);
}

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

int main() {

    ios::sync_with_stdio(false);

    cin >> n >> m >> r >> k;

    priority_queue<TLLII> q;
    q.emplace(get_freq(n/2, m/2), n/2, m/2);

    double sum = 0;
    int count = 0;
    unordered_set<long long> vis;
    vis.insert(encode(n/2, m/2));
    for (int x, y; !q.empty() && count<k; ++count) {
        long long freq;
        tie(freq, x, y) = q.top();
        q.pop();

        sum += freq;

        for (int dir=0; dir<4; ++dir) {
            int tx = x+dx[dir], ty = y+dy[dir];
            long long ind = encode(tx, ty);
            if (tx>=0 && tx<n && ty>=0 && ty<m && vis.find(ind)==vis.end()) {
                vis.insert(ind);
                q.emplace(get_freq(tx, ty), tx, ty);
            }
        }
    }

    cout.precision(10);
    cout << fixed << sum / ((long long)(n-r+1)*(m-r+1)) << endl;
    return 0;
}