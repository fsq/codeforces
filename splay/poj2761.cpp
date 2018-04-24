#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>

#define cind(x) scanf("%d", &x)

using namespace std;

// harsh time limit
// change int[] to vector gives TLE

class Node {
public:
    int val, fa, size, rep;
    int s[2];
    Node(): val(0), fa(0), rep(0), size(0) { s[0] = s[1] = 0; }
    Node(int v): val(v), fa(0), size(1), rep(1) { s[0] = s[1] = 0; }
};

const int MAXN = 200001;

Node t[MAXN];
int dogs[MAXN];
int ans[MAXN];
int seg[MAXN][5];

int n, m, root = 0;
int nodecnt = 1;

inline void setroot(int x) { t[root=x].fa = 0; }

inline void link(int x, int p, bool right) {
    if (p) {
        t[p].s[right] = x;
        t[p].size = t[p].rep + t[t[p].s[0]].size + t[t[p].s[1]].size;
    }
    if (x) t[x].fa = p;
}

void rotate(int y, bool right) {
    int x = t[y].s[!right], p = t[y].fa;
    link(x, p, y==t[p].s[1]);
    link(t[x].s[right], y, !right);
    link(y, x, right);
}

void splay(int x) {
    while (t[x].fa) {
        int p = t[x].fa;
        bool lx = t[p].s[0] == x;
        if (p==root)
            rotate(p, lx);
        else {
            int pp = t[p].fa;
            bool lp = t[pp].s[0] == p;
            if (lx ^ lp) 
                rotate(p, lx), rotate(pp, lp);
            else
                rotate(pp, lp), rotate(p, lx);
        }
    }
    root = x;
}

void insert(int v) {
    int p = root, pp = 0;
    while (p) {
        pp = p;
        if (t[p].val==v) {
            ++t[p].size, ++t[p].rep;
            splay(p);
            return;
        } else 
            p = t[p].s[v>t[p].val];
    }
    int ind = nodecnt;
    t[nodecnt++] = Node(v);
    link(ind, pp, v>t[pp].val);
    splay(ind);
}

inline int find_min(int x) {
    if (x) 
        while (t[x].s[0]) x = t[x].s[0];
    return x;
}

inline int find(int v) {
    int x = root;
    while (x) 
        if (t[x].val==v)
            return x;
        else 
            x = t[x].s[v>t[x].val];
    return x;
}

void remove(int v) {
    int x = find(v);
    if (!x) return;
    splay(x);
    --t[x].size, --t[x].rep;
    if (t[x].rep) return;

    int ls = t[x].s[0], rs = t[x].s[1];
    if (!(ls && rs))
        setroot(ls ? ls : (rs ? rs : 0));
    else {
        int suc = find_min(rs);
        if (suc==rs) { 
            link(ls, suc, false);
            setroot(suc);
        } else {
            int psuc = t[suc].fa;
            link(t[suc].s[1], psuc, false);
            setroot(suc);
            link(ls, suc, false);
            link(rs, suc, true);
            splay(psuc); // remember to splay here !
        }
    }
}

int query(int k) {
    int x = root;
    while (x) {
        int ls = t[x].s[0] ? t[t[x].s[0]].size : 0;
        if (k<=ls)
            x = t[x].s[0];
        else if (k<=ls+t[x].rep) {
            splay(x);
            return t[x].val;
        } else {
            k -= ls + t[x].rep;
            x = t[x].s[1];
        }
    }
    return 0;
}

int cmp(const void *a,const void *b) {
    const int *x =  (const int*)a;
    const int *y =  (const int*)b;
    return x[0]==y[0] ? x[1]-y[1] : x[0]-y[0];
}

int main() {
    cind(n), cind(m);
    for (int j,i=1; i<=n; ++i) {
        cind(j);
        dogs[i] = j;
    }

    for (int i=1; i<=m; ++i) 
        cind(seg[i][0]), cind(seg[i][1]), cind(seg[i][2]), seg[i][3] = i;

    qsort(seg+1, m, sizeof(*seg), cmp);

    int start = 1, end = 1;
    for (int segid, ind,l,r,i=1; i<=m; ++i) {
        l = seg[i][0], r = seg[i][1];
        ind = seg[i][2], segid = seg[i][3];
        while (end<=r) insert(dogs[end++]);
        while (start<l)  remove(dogs[start++]);
        ans[segid] = query(ind);

    }
    for (int i=1; i<=m; ++i) printf("%d\n", ans[i]);

    return 0;
}
