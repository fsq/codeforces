#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

vector<string> a(10);
vector<int> dx = {-1,0,1,0};
vector<int> dy = {0,1,0,-1};
int n = 10;

int encode(int fx, int fy, int fd, int cx, int cy, int cd) {
    return fx*100000 + fy*10000 + fd*1000 + cx*100 + cy*10 + cd;
}

void decode(int state, int& fx, int& fy, int& fd, int& cx, int& cy, int& cd) {
    fx = state / 100000; state %= 100000;
    fy = state / 10000 ; state %= 10000 ;
    fd = state / 1000  ; state %= 1000  ;
    cx = state / 100   ; state %= 100   ;
    cy = state / 10    ; state %= 10    ;
    cd = state;
}

void move(int& x, int& y, int& d) {
    int tx=x+dx[d], ty=y+dy[d];
    if (tx>=0 && tx<10 && ty>=0 && ty<10 && a[tx][ty]=='.') {
        x = tx, y = ty;
        return;
    }
    d = (d+1) % 4;
}

int main() {
    ios::sync_with_stdio(false);
    int fx, fy, fd=0, cx, cy, cd=0;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        for (int j=0; j<n; ++j)
            if (a[i][j]=='F') {
                fx = i, fy = j;
                a[i][j] = '.';
            } else if (a[i][j]=='C') {
                cx = i, cy = j;
                a[i][j] = '.';
            }
    }

    int state = encode(fx, fy, fd, cx, cy, cd); 
    vector<int> vis(1000000);
    bool found = false;

    for (int stp=1; ; ++stp) {
        decode(state, fx, fy, fd, cx, cy, cd);

        move(fx, fy, fd), move(cx, cy, cd);

        if (fx==cx && fy==cy) {
            cout << stp << endl;
            found = true;
            break;
        }

        state = encode(fx,fy,fd, cx,cy,cd);
        if (!vis[state]) 
            vis[state] = true;
        else 
            break;
    }
    if (!found)
        cout << 0 << endl;

    return 0;
}