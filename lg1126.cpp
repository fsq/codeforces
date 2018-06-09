#include <cstdio>
#include <algorithm>
#include <queue>
#define REP(i, a, b) for (int i=(a); i<=(b); ++i)

using namespace std;

int n, m, a[54][54], sx, sy, tx, ty;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool vis[54][54][4];

int main() {
    scanf("%d %d", &n, &m);
    REP(i, 1, n) REP(j, 1, m) {
        int x;
        scanf("%d", &x);
        if (x) 
            a[i][j] = a[i][j+1] = a[i+1][j] = a[i+1][j+1] = 1;
    }

    char cdir;
    scanf("%d %d %d %d %c", &sx, &sy, &tx, &ty, &cdir);

    if (sx==tx && sy==ty) {
        printf("0\n");
        return 0;
    }

    sx++, sy++, tx++, ty++, n++, m++;

    REP(i, 1, m) a[1][i] = a[n][i] = 1;
    REP(i, 1, n) a[i][1] = a[i][m] = 1;

    int dir;
    if (cdir=='N') dir = 0; 
        else if (cdir=='E') dir = 1;
        else if (cdir=='S') dir = 2;
        else if (cdir=='W') dir = 3;


    queue<vector<int>> q;
    q.push({sx, sy, dir, 0});
    vis[sx][sy][dir] = true;

    while (!q.empty()) {
        vector<int> now = move(q.front());
        q.pop();

        int x = now[0], y = now[1], dir = now[2], dis = now[3];
        for (int d=1; d<=3; ++d) {
            int xx = x + d*dx[dir], yy = y + d*dy[dir];
            if (xx>=1 && xx<=n && yy>=1 && yy<=m && !vis[xx][yy][dir]) 
                if (!a[xx][yy]) {
                    if (xx==tx && yy==ty) {
                        printf("%d\n", dis+1);
                        return 0;
                    }
                    q.push({xx, yy, dir, dis+1});
                    vis[xx][yy][dir] = true;
                } else 
                    break;
            else {}
        }

        for (int turn=-1; turn<=1; turn+=2) {
            int tdir = (dir+turn+4) % 4;
            if (!vis[x][y][tdir]) {
                q.push({x, y, tdir, dis+1});
                vis[x][y][tdir] = true;
            }
        }
    }

    printf("%d\n", -1);



    return 0;
}