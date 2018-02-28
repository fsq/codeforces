#include <cstdio>
#include <memory>

using namespace std;

// recursive segment tree
// adding from tail to front

const int MAXN = 2e5 + 7;

int n;
int pos[MAXN], val[MAXN];
int t[MAXN<<2 | 1];
int ind[MAXN];

inline int ls(int i) { return i<<1; }
inline int rs(int i) { return i<<1 | 1; }
inline int get_mid(int l, int r) { return (l+r)>>1; }
void refresh(int i) { t[i] = t[ls(i)] + t[rs(i)]; }

void build(int node, int l, int r) {
    if (l==r)
        t[node] = 1;
    else {
        int mid = get_mid(l, r);
        build(ls(node), l, mid);
        build(rs(node), mid+1, r);
        refresh(node);
    }
}

void update(int node, int l, int r, int p, int v) {
    --t[node];
    if (l==r) 
        ind[l] = v;
    else {
        int mid = get_mid(l, r);
        if (p<=t[ls(node)])
            update(ls(node), l, mid, p, v);
        else
            update(rs(node), mid+1, r, p-t[ls(node)], v);
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i=0; i<n; ++i) 
            scanf("%d %d", &pos[i], &val[i]);
        
        build(1, 1, n);

        for (int i=n-1; i>=0; --i) {
            int p = pos[i], v = val[i];
            update(1, 1, n, p+1, v);
        }

        for (int i=1; i+1<=n; ++i)
            printf("%d ", ind[i]);;
        printf("%d\n", ind[n]);
    }
    return 0;
}