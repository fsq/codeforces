#include <vector>
#include <cstdio>
#include <queue>
#include <tuple>
#include <cmath>
#include <cstring>

#define cinc(c) scanf("%c", &c)
#define cind(x) scanf("%d", &x)
#define REP(i, n) for (int i=0; i<(n); ++i)
#define REPR(i, a, b) for (int i=(a); i<(b); ++i)
#define fill(x, v) memset(x, (v), sizeof(x))
#define T0(x) get<0>((x))
#define T1(x) get<1>((x))
#define T2(x) get<2>((x))

using namespace std;
using TII = tuple<int,int,int>;
using PII = pair<int,int>;

char a[1007][1007];
const int inf = 2000000;

int main() {
    int n, m, k;
    cind(n), cind(m), cind(k);
    int dis[n+1][m+1];

    char c;
    cinc(c); // \n
    REP(i, n) {
        REP(j, m) {
            dis[i][j] = inf;
            cinc(c);
            a[i][j] = c;
        }
        cinc(c);
    }

    int sx, sy, tx, ty;
    cind(sx), cind(sy), cind(tx), cind(ty);
    --sx, --sy, --tx, --ty;
    dis[sx][sy] = 0 ;


    int ansdis = 0;
    bool found = false;

    if (!(sx==tx && sy==ty)) {
        queue<PII> q;
        q.push(PII(sx, sy));
        
        bool vis[n+1][m+1];
        fill(vis, false);
        vis[sx][sy] = true;

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        while (!q.empty()) {
            auto tp = q.front();
            q.pop();
            int x = tp.first, y = tp.second;
            REP(dir, 4) 
                REPR(d, 1, k+1) {
                    int xx = x+dx[dir]*d, yy = y+dy[dir]*d;

                    // 100ms
                    if (xx>=0 && xx<n && yy>=0 && yy<m 
                        && a[xx][yy]=='.' && dis[xx][yy]>=dis[x][y]+1) {
                        if (dis[xx][yy]==inf) {
                            vis[xx][yy] = true;
                            dis[xx][yy] = dis[x][y] + 1;
                            if (xx==tx && yy==ty) {
                                found = true;
                                break;
                            }
                            q.push(PII(xx, yy));
                        }
                    } else 
                        break;

                    // 1300ms
                    // if (xx>=0 && xx<n && yy>=0 && yy<m) {
                    //     if (a[xx][yy]=='#') break;
                    //     if (!vis[xx][yy]) {
                    //         vis[xx][yy] = true;
                    //         dis[xx][yy] = dis[x][y] + 1;

                    //         if (xx==tx && yy==ty) {
                    //                 found = true;
                    //                 break;
                    //             }
                    //         q.push(PII(xx, yy));
                    //     }
                    // }
                }
            
            if (found) break;
        }
    } else 
        found = true;

    if (found) 
        printf("%d\n", dis[tx][ty]);
    else 
        printf("-1\n");


    return 0;
}