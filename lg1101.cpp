#include <cstdio>
#include <string>

using namespace std;
int n;
char a[103][103];
char s[103][103];

string match = "yizhong";

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool ok(int i, int j, int dir) {
    for (int c=0; c<match.size(); ++c) {
        int x = i + dx[dir]*c, y = j + dy[dir]*c;
        if (!(x>0 && x<=n && y>0 && y<=n && a[x][y]==match[c]))
            return false;
    }
    return true;
}

void fill(int i, int j, int dir) {
    for (int c=0; c<match.size(); ++c) {
        s[i][j] = match[c];
        i += dx[dir];
        j += dy[dir];
    }
}

int main() {
    scanf("%d\n", &n);
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            scanf("%c", &a[i][j]);
            s[i][j] = '*';
        }
        scanf("\n");
    }

    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            if (a[i][j]=='y')
                for (int dir=0; dir<8; ++dir)
                    if (ok(i, j, dir)) 
                        fill(i, j, dir);
                    

    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j)
            printf("%c", s[i][j]);
        printf("\n");
    }


    return 0;
}