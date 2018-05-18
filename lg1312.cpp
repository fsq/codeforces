#include <algorithm>
#include <cstring>
#include <string>
#define REP(i,a,b) for (int i=(a);i<=(b);++i)

using namespace std;

int a[5][7];
int step[5][3];
int n;
bool mark[5][7];

bool finish(int a[5][7]) {
    REP(i, 0, 4) REP(j, 0, 6) if (a[i][j]) return false;
    return true;
}

void push(int a[5][7], int x, int y, int l, int b[5][7]) {
    REP(i, 0, 4) REP(j, 0, 6) b[i][j] = a[i][j];
    int tx = x + l;
    if (b[tx][y]) 
        swap(b[tx][y], b[x][y]);
    else {
        b[tx][y] = b[x][y];
        for (int ty=y; ty>0 && !b[tx][ty-1]; --ty)
            swap(b[tx][ty], b[tx][ty-1]);
        for (int ty=y; ty<6; ++ty)
            b[x][ty] = b[x][ty+1];
        b[x][6] = 0;
    }
}

bool can_clear(int a[5][7]) {
    bool find=false;
    memset(mark, false, sizeof(mark));
    REP(i, 0, 4)
        for (int j=6; j>=0; --j) 
            if (a[i][j]) {
                if (i+2<=4 && a[i][j]==a[i+1][j] && a[i+1][j]==a[i+2][j]) 
                    find = mark[i][j] = mark[i+1][j] = mark[i+2][j] = true;
                if (j-2>=0 && a[i][j]==a[i][j-1] && a[i][j-1]==a[i][j-2]) 
                    find = mark[i][j] = mark[i][j-1] = mark[i][j-2] = true;
            }
    if (find)
        REP(i, 0, 4)  REP(j, 0, 6)
        if (mark[i][j])
            a[i][j] = 0;
    return find;
}

void clear(int b[5][7]) {
    while (can_clear(b)) {
        REP(i, 0, 4) {
            auto& a = b[i];
            for (int l=0,r=0; r<7; ++r)
                if (a[r]) 
                    swap(a[l++], a[r]);
        }
    }
}

bool dfs(int i, int a[5][7], int step[5][3]) {
    if (i==n) {
        return finish(a);
    } else {
        REP(x, 0, 4) REP(y, 0, 6)
            if (a[x][y])
                for (int l=1; l>=-1; l-=2) 
                    if (x+l>=0 && x+l<5 && !(l==-1 && a[x+l][y])) {
                        int b[5][7];
                        memset(b, 0, sizeof(b));
                        push(a, x, y, l, b);
                        clear(b);
                        
                        step[i][0] = x;
                        step[i][1] = y;
                        step[i][2] = l;
                        if (dfs(i+1, b, step)) return true;
                    }
    }
    return false;
}

int main() {
    scanf("%d", &n);
    for (int x,j,i=0; i<5; ++i) {
        j = 0;
        scanf("%d", &x);
        while (x) {
            a[i][j++] = x;
            scanf("%d", &x);
        }
    }

    if (!dfs(0, a, step)) 
        printf("-1\n");
    else
        for (int i=0; i<n; ++i)
            printf("%d %d %d\n", step[i][0], step[i][1], step[i][2]);

    return 0;
}