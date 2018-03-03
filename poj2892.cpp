#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;

const int MAXN = 50010;

int stk[MAXN], ptr;
int t[MAXN<<1 | 1][2];

inline int ls(int x) { return x<<1; }
inline int rs(int x) { return x<<1 | 1; }

void refresh(int x) { 
    t[x][0] = min(t[ls(x)][0], t[rs(x)][0]);
    t[x][1] = max(t[ls(x)][1], t[rs(x)][1]);
}

void build() {
    for (int i=0; i<n; ++i) {
        t[i+n][0] = n;
        t[i+n][1] = -1;
    }
    for (int i=n-1; i>0; --i)
        refresh(i);
}

void update(int p, int flag) {
    p += n;
    if (flag==1) 
        t[p][0] = t[p][1] = p - n;
    else {
        t[p][0] = n;
        t[p][1] = -1;
    }
    while (p>1)
        p>>=1, refresh(p);
}

int get_max(int l, int r) {
    int res = -1;
    for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
        if (l&1) res = max(res, t[l++][1]);
        if (r&1) res = max(res, t[--r][1]);
    }
    return res;
}

int get_min(int l, int r) {
    int res = n;
    for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
        if (l&1) res = min(res, t[l++][0]);
        if (r&1) res = min(res, t[--r][0]);
    }
    return res;
}


int main() {
    scanf("%d %d\n", &n,&m);

    build();

    char c;
    int p;

    ptr = 0;
    while (m--) {
        scanf("%c", &c);
        if (c=='D') {
            scanf("%d\n", &p);
            stk[ptr++] = p;
            update(p-1, 1);
        } else if (c=='Q') {
            scanf("%d\n", &p);
            --p;
            if (t[n+p][0]==p) 
                printf("%d\n", 0);
            else {
                int l = get_max(0, p);
                int r = get_min(p+1, n);
                printf("%d\n", r-l-1);
            }
        } else {
            scanf("\n");
            p = stk[--ptr];
            update(p-1, 0);
        }
    }

    return 0;
}