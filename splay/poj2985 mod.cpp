#include <cstdio>
#include <vector>
#define cind(x) scanf("%d", &x)
using namespace std;

int n, m;

class Cat {
public:
    int fa, size;
    int gid;
    int rank;
    Cat(int f):fa(f), size(1), rank(0) {}
};

class Node {
public:
    int s[2];
    int fa, size, val;
    int rep;
    Node() { s[0] = s[1] = 0; }
    Node(int v, int f):val(v), size(1), fa(f), rep(1) { s[0] = s[1] = 0; }
};


vector<Node> t(1);
vector<Cat> cat;

int root = 0;

int find(int x) {
    return cat[x].fa==x ? x : cat[x].fa = find(cat[x].fa);
}

// similar to segment tree 
void refresh(int x) {
    t[x].size = t[x].rep;
    for (int i=0; i<2; ++i)
        t[x].size += t[x].s[i] ? t[t[x].s[i]].size : 0;
}

// link x as a child of pp
// right ? right child : left child
void link(int x, int pp, bool right) {
    if (pp) {
        t[pp].s[right] = x;
        refresh(pp);
    }
    if (x) t[x].fa = pp;
}

void rotate(int y, bool right) {
    int x = t[y].s[!right], p = t[y].fa;

    link(x, p, t[p].s[1]==y);
    link(t[x].s[right], y, !right);
    link(y, x, right);

    // refresh(y), refresh(x);
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

int insert(int val) {
    int now = root, pp = 0;
    while (now) {
        if (t[now].val==val) {
            ++t[now].rep;
            ++t[now].size;
            splay(now);
            return now;
        }
        pp = now, now = t[now].s[val>t[now].val];
    }
    now = t.size();
    t.push_back(Node(val, pp));
    link(now, pp, val>t[pp].val);
    splay(now);
    return now;
}

int find_min(int x) {
    if (x) while (t[x].s[0]) x = t[x].s[0];
    return x;
}

void remove(int x) {
    if (x==0) return;
    splay(x);
    --t[x].rep, --t[x].size;
    if (t[x].rep>0) return;
    if (!t[x].s[0] && !t[x].s[1]) 
        root = 0;
    else if (!t[x].s[1]) {
        root = t[x].s[0];
        t[root].fa = 0;
    } else {
        int suc = find_min(t[x].s[1]), psuc = t[suc].fa;

        link(t[suc].s[1], psuc, suc==t[psuc].s[1]);
        t[x].rep = t[suc].rep;
        t[x].val = t[suc].val;
        swap(t[suc], t[x]);
        root = suc; 
        link(t[root].s[0], root, false);
        link(t[root].s[1], root, true);

        if (psuc!=x) splay(psuc); // psuc!=x !! otherwise psuc becomes root
    }
}

int query(int k) {
    int now = root;
    while (now) {
        int cnt = t[now].s[0] ? t[t[now].s[0]].size : 0;
        if (k<=cnt)
            now = t[now].s[0];
        else if (k<=cnt+t[now].rep) {
            splay(now);
            return t[now].val;
        } else {
            k -= cnt + t[now].rep;
            now = t[now].s[1];
        }
    }
    return 0;
}

int merge(int x, int y) {
    if (cat[x].rank>cat[y].rank) {
        cat[y].fa = x;
        cat[x].size += cat[y].size;
        return x;
    } else {
        cat[x].fa = y;
        cat[y].size += cat[x].size;
        if (cat[x].rank==cat[y].rank) ++cat[y].rank;
        return y;
    }
}

int main() {
    cind(n), cind(m);
    for (int i=0; i<n; ++i) {
        cat.push_back(Cat(i));
        cat.back().gid = insert(1);
    }

    int op;
    int indp = n;
    while (m--) {
        cind(op);
        if (op == 0) {
            int x, y;
            cind(x), cind(y);
            --x, --y;

            x = find(x), y = find(y);
            if (x != y) {
                --indp;
                remove(cat[x].gid);
                remove(cat[y].gid);
                int fa = merge(x, y);
                cat[fa].gid = insert(cat[fa].size);
            }
        } else {
            int x;
            cind(x);
            x = indp - x + 1;
            printf("%d\n", query(x));
        }
    }
    return 0;
}