#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int N = 101;
const int MAX_CHAR = 256;

int f[N][N][MAX_CHAR];
char ch[N][N];
vector<vector<int>> edges;

bool dp(int x, int y, int pre) {
    if (f[x][y][pre]!=0)
        return f[x][y][pre]==1 ? true : false;

    int& ans = f[x][y][pre];
    ans = -1;

    for (auto nxt : edges[x])
        if (ch[x][nxt]>=pre && !dp(y, nxt, ch[x][nxt])) {
            ans = 1;
            break;
        }
    // printf("%d %d %c %d\n", x, y, pre, ans);
    return ans==1;
}

int main() {
    int n, m;

    ios::sync_with_stdio(false);

    cin >> n >> m;

    edges = vector<vector<int>>(n, vector<int>{});
    char c;
    for (int u,v,i=0; i<m; ++i) {
        cin >> u >> v >> c;
        --u, --v;
        edges[u].push_back(v);
        ch[u][v] = c;
    }   

    for (int i=0; i<n; ++i){
        string now;
        for (int j=0; j<n; ++j) 
            if (dp(i, j, 0))
                now.push_back('A');
            else 
                now.push_back('B');
        cout << now << endl;
    }


    return 0;
}