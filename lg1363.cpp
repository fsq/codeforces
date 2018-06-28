#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define REP(i,a,b) for (int i=(a);i<=(b);++i)

using namespace std;

int n, m, cc, x, y;
char a[2007][2007];
int s[2007][2007];
vector<pair<int,int>> e[2250000];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int i, int j, const int cc) {
	s[i][j] = cc;
	for (int tx,ty,dir=0; dir<4; ++dir) {
		tx = i + dx[dir], ty = j + dy[dir];
		if (tx>0 && tx<=n && ty>0 && ty<=m && a[tx][ty]!='#' && !s[tx][ty])
			dfs(tx, ty, cc);
	}
}

void connect(int x, int y) {
	for (int tx,ty,dir=0; dir<4; ++dir) {
		tx = x + dx[dir], ty = y + dy[dir];
		if (tx>0 && tx<=n && ty>0 && ty<=m) continue;
		tx = (tx-1+n) % n + 1;
		ty = (ty-1+m) % m + 1;
		if (a[tx][ty]!='#') e[s[x][y]].push_back({s[tx][ty], dir});
	}
}

bool loop(bool vis[], int cnt[], int x) {
	vis[x] = true;
	for (auto& v : e[x]) {
		cnt[v.second]++;
		if (vis[v.first]) {
			if (cnt[0]!=cnt[2] || cnt[1]!=cnt[3]) return true;
		} else 
			if (loop(vis, cnt, v.first)) return true;
		
		cnt[v.second]--;
	}
	return false;
}

int main() {
	while (scanf("%d %d\n", &n, &m)!=EOF) {

		
		REP(i, 1, n) {
			REP(j, 1, m) {
				scanf("%c", &a[i][j]);
				s[i][j] = 0;
				if (a[i][j]=='S') 
					x = i, y = j;
			}
			scanf("\n");
		}

		cc = 0;
		REP(i, 1, n) REP(j, 1, m) 
			if (a[i][j]!='#' && !s[i][j]) {
				dfs(i, j, ++cc);
				e[cc].clear();
			}
			
		REP(j, 1, m) connect(1, j), connect(n, j);
		REP(i, 1, n) connect(i, 1), connect(i, m);

		REP(i, 1, cc) {
			sort(e[i].begin(), e[i].end());
			e[i].resize(unique(e[i].begin(), e[i].end()) - e[i].begin());
		}

		bool vis[cc+1];
		memset(vis, false, sizeof(vis));
		int cnt[] = {0,0,0,0};
		if (loop(vis, cnt, s[x][y])) 
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}