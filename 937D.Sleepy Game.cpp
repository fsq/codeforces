#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
#define cind(x) scanf("%d", &x)

using namespace std;
const int MAXN = 100007;

int n, m;

vector<int> e[MAXN];
bool v[MAXN][2];
int pre[MAXN][2];
bool sink[MAXN];
int s;
int nsink = 0;
int color[MAXN];

bool dfs(int now) {
    color[now] = 1;
    for (auto nxt : e[now])
        if (color[nxt]==0 && dfs(nxt))
            return true;
        else if (color[nxt]==1) 
            return true;
    color[now] = 2;
    return false;
}

bool loop() {
    memset(color, 0, sizeof(color));
    return dfs(s);
}

int main(  ) {
    memset(v, false, sizeof(v));
    memset(sink, false, sizeof(sink));

    cind(n), cind(m);
    for (int j,ni,i=1; i<=n; ++i) {
        cind(ni);
        if (ni==0) {
            sink[i] = true;
            ++nsink;
        }
        while (ni--) {
            cind(j);
            e[i].push_back(j);
        }
    }
    cind(s);

    if (sink[s]) {
        printf("Lose\n");
        return 0;
    }

    if (nsink==0) {
        printf("Draw\n");
        return 0;
    }

    bool win = false;
    bool exc = false;
    int end = 0;

    queue<pair<int,int>> q;
    q.push({s, 0});
    v[s][0] = true;
    pre[s][0] = 0;

    while (!q.empty()) {
        int now = q.front().first;
        int l   = q.front().second;
        q.pop();

        for (auto nxt : e[now]) {
            int b = 1 ^ (l&1);
            if (!v[nxt][b]) {
                v[nxt][b] = true;
                pre[nxt][b] = now;
                if (sink[nxt] && b) {
                    win = true;
                    end = nxt;
                    break;
                }
                if (l+1==1000000) 
                    exc = true;
                else
                    q.push({nxt, l+1});
            } 
        }
        if (win) break;
    }
    if (win) {
        printf("Win\n");
        vector<int> ans;
        int l = 1;
        while (end) {
            ans.push_back(end);
            end = pre[end][l];
            l ^= 1;
        }
        for (int i=ans.size()-1; i>=0; --i)
            printf("%d ", ans[i]);
        return 0;
    }
    if (exc || loop()) 
        printf("Draw\n");
    else 
        printf("Lose\n");


    return 0;
}