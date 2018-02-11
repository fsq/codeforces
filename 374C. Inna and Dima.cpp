#include <vector>
#include <iostream>

using namespace std;

int n, m;
bool loop;
vector<vector<int>> f;
vector<vector<char>> map;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

char get_next(char x) {
    switch (x) {
        case 'D' : return 'I';  break;
        case 'I' : return 'M';  break;
        case 'M' : return 'A';  break;
        case 'A' : return 'D';  break;
    }
    return ' ';
}

int dfs(int x, int y) {
    if (f[x][y]==-2) {
        loop = true;
        return 0;
    }
    if (f[x][y]!=-1)
        return f[x][y];

    f[x][y] = -2;
    int ans = 1;
    char aim = get_next(map[x][y]);
    for (int dir=0; dir<4; ++dir) {
        int tx = x+dx[dir], ty = y+dy[dir];
        if (tx>=0 && tx<n && ty>=0 && ty<m && map[tx][ty]==aim) {
            int nxt = dfs(tx, ty);
            if (loop)
                return 0;
            ans = max(ans, nxt+1);
        }
    }
    f[x][y] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    loop = false;
    cin >> n >> m;

    char t;
    for (int i=0; i<n; ++i) {
        vector<char> row;
        for (int j=0; j<m; ++j) {
            cin >> t;
            row.push_back(t);
        }
        map.push_back(row);
    }

    f = vector<vector<int>>(n, vector<int>(m, -1));

    int ans = 0;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j)
            if (map[i][j]=='D' && f[i][j]==-1) {
                int ts = dfs(i, j);
                ans = max(ans, ts / 4);
                if (loop) break;
            }
        if (loop)
            break;
    }

    if (loop)
        cout << "Poor Inna!" << endl;
    else if (ans==0)
        cout << "Poor Dima!" << endl;
    else 
        cout << ans << endl;

    return 0;
}