#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define REP(i,a,b) for (int i=(a);i<=(b);++i)
#define FOR(i,a)   for (int i=0; i<(a); ++i)

using namespace std;

int n, m, sx, sy;
char a[1600][1600];
bool vis[1600][1600];
pair<int,int> bias[1600][1600];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool dfs(int x, int y, int p[]) {
	vis[x][y] = true;
	bias[x][y] = {p[0], p[1]};
	for (int bx,by,tx,ty,dir=0; dir<4; ++dir) {
		tx = x + dx[dir];
		ty = y + dy[dir];
		bx = tx < 0 ? -1 : (tx>=n ? 1 : 0);
		by = ty < 0 ? -1 : (ty>=m ? 1 : 0);
		tx = (tx + n) % n, ty = (ty + m) % m;
		if (a[tx][ty]=='#') continue;

		p[0] += bx, p[1] += by;
		if (vis[tx][ty]) {
			if (bias[tx][ty]!=pair<int,int>{p[0], p[1]}) return true;
		} else 
			if (dfs(tx, ty, p)) return true;
		
		p[0] -= bx, p[1] -= by;

	}
	return false;
}

int main() {
	while (scanf("%d %d\n", &n, &m)!=EOF) {
		FOR(i, n) {
			FOR(j, m) {
				scanf("%c", &a[i][j]);
				if (a[i][j]=='S') sx = i, sy = j;
			}
			scanf("\n");
		}

		memset(vis, false, sizeof(vis));
		int p[] = {0, 0};
		if (dfs(sx, sy, p))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}