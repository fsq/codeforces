#include <vector>
#include <algorithm>
#include <deque>
#include <cstdio>
#define REP(i,a,b) for (int i=(a);i<=(b);++i)

using namespace std;
const int N = 2003;

int n, m;
int board[N][N], a[N][N], l[N][N], r[N][N];

void process(int a[], int b[], int l[], int r[]) {
    deque<int> q;
    int last = 1;
    REP(i, 1, m) 
        if (!q.empty() && !(b[i]^b[q.back()])) {
            while (!q.empty()) {
                r[q.back()] = i - q.back();
                q.pop_back();
            }
            l[i] = 1;
            last = i;
            q.push_back(i);
        } else {
            while (!q.empty() && a[q.back()]>=a[i]) {
                r[q.back()] = i - q.back();
                q.pop_back();
            }
            l[i] = q.empty() ? i-last+1 : i-q.back();
            q.push_back(i);
        }
}

int main() {
    scanf("%d %d", &n, &m);
    REP(i, 1, n) REP(j, 1, m) scanf("%d", &board[i][j]);

    REP(i, 1, m) a[1][i] = 1;
    REP(i, 2, n) REP(j, 1, m) 
        a[i][j] = (board[i][j]^board[i-1][j]) ? a[i-1][j]+1 : 1;

    REP(i, 1, n) process(a[i], board[i], l[i], r[i]);

    int sqr=0, rect=0;

    REP(i, 1, n) REP(j, 1, m) {
        int w = r[i][j] + l[i][j] - 1;
        int len = min(w, a[i][j]);
        sqr = max(sqr, len*len);
        rect = max(rect, w*a[i][j]);
    }
    printf("%d\n%d\n", sqr, rect);

    return 0;
}