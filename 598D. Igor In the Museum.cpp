#include <vector>
#include <string>
#include <iostream>

using namespace std;
int n, m, k;

vector<vector<int>> ans;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

void see(vector<vector<int>>& map, int x, int y, int& count) {
    map[x][y] = -1;

    for (int dir=0; dir<4; ++dir) {
        int tx=x+dx[dir], ty=y+dy[dir];
        if (tx>=0 && tx<n && ty>=0 && ty<m) 
            if (map[tx][ty]==0) {
                see(map, tx, ty, count);
            } else if (map[tx][ty]==1)
                ++count;
    }
}

void fill(vector<vector<int>>& map, int x, int y, int count) {
    ans[x][y] = count;
    map[x][y] = 1;
    for (int dir=0; dir<4; ++dir) {
        int tx=x+dx[dir], ty=y+dy[dir];
        if (tx>=0 && tx<n && ty>=0 && ty<m && map[tx][ty]==-1) 
        fill(map, tx, ty, count);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;

    vector<vector<int>> map;
    for (int i=0; i<n; ++i) {
        vector<int> row;
        char c;
        for (int j=0; j<m; ++j) {
            cin >> c;
            row.push_back(c=='.' ? 0 : 1);
        }
        map.push_back(row);
    }

    ans = vector<vector<int>>(n, vector<int>(m, 0));
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            if (map[i][j]==0) {
                int count = 0;
                see(map, i, j, count);
                fill(map, i, j, count);
            }
    for (int i,j,t=0; t<k; ++t) {
        cin >> i >> j;
        cout << ans[i-1][j-1] << '\n';
    }


    return 0;
}